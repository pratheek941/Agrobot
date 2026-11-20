
import cv2
import mediapipe as mp
import time

# MediaPipe setup
BaseOptions = mp.tasks.BaseOptions
HandLandmarker = mp.tasks.vision.HandLandmarker
HandLandmarkerOptions = mp.tasks.vision.HandLandmarkerOptions
RunningMode = mp.tasks.vision.RunningMode

options = HandLandmarkerOptions(
    base_options=BaseOptions(
        model_asset_path="hand_landmarker.task"
    ),
    running_mode=RunningMode.VIDEO,
    num_hands=1,
    min_hand_detection_confidence=0.7,
    min_tracking_confidence=0.7
)

def finger_up(hand, tip, pip):
    return hand[tip].y < hand[pip].y


def detect_gesture(hand):

    index = finger_up(hand, 8, 6)
    middle = finger_up(hand, 12, 10)
    ring = finger_up(hand, 16, 14)
    pinky = finger_up(hand, 20, 18)

    # Open palm
    if index and middle and ring and pinky:
        return "STOP"

    # Peace sign
    if index and middle and not ring and not pinky:
        return "LEFT"

    # Index finger only
    if index and not middle and not ring and not pinky:
        return "RIGHT"

    # Thumbs up
    if (not index and not middle and
        not ring and not pinky and
        hand[4].y < hand[3].y):
        return "FORWARD"

    # Thumbs down
    if (not index and not middle and
        not ring and not pinky and
        hand[4].y > hand[3].y):
        return "BACKWARD"

    return "UNKNOWN"


camera = cv2.VideoCapture(0)

if not camera.isOpened():
    print("Camera not detected!")
    exit()

print("AGROBOT GESTURE RECOGNITION STARTED")

with HandLandmarker.create_from_options(options) as landmarker:

    while True:

        success, frame = camera.read()

        if not success:
            break

        frame = cv2.flip(frame, 1)

        rgb = cv2.cvtColor(
            frame,
            cv2.COLOR_BGR2RGB
        )

        mp_image = mp.Image(
            image_format=mp.ImageFormat.SRGB,
            data=rgb
        )

        timestamp = int(time.monotonic() * 1000)

        result = landmarker.detect_for_video(
            mp_image,
            timestamp
        )

        gesture = "NO HAND"

        if result.hand_landmarks:

            hand = result.hand_landmarks[0]

            gesture = detect_gesture(hand)

            h, w, _ = frame.shape

            for point in hand:
                x = int(point.x * w)
                y = int(point.y * h)

                cv2.circle(
                    frame,
                    (x, y),
                    5,
                    (0, 255, 0),
                    -1
                )

        cv2.putText(
            frame,
            "GESTURE: " + gesture,
            (20, 50),
            cv2.FONT_HERSHEY_SIMPLEX,
            1,
            (0, 255, 0),
            2
        )

        cv2.imshow(
            "AGROBOT GESTURE CONTROL",
            frame
        )

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

camera.release()
cv2.destroyAllWindows()
