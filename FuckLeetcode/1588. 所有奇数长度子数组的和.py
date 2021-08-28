class Solution:
    def __init__(self):
        self.cao = [
            [],
            [1],
            [1, 1],
            [2, 2, 2],
            [2, 3, 3, 2],
            [3, 4, 5, 4, 3],
            [3, 5, 6, 6, 5, 3],
            [4, 6, 8, 8, 8, 6, 4],
            [4, 7, 9, 10, 10, 9, 7, 4],
            [5, 8, 11, 12, 13, 12, 11, 8, 5],
            [5, 9, 12, 14, 15, 15, 14, 12, 9, 5],
            [6, 10, 14, 16, 18, 18, 18, 16, 14, 10, 6],
            [6, 11, 15, 18, 20, 21, 21, 20, 18, 15, 11, 6],
            [7, 12, 17, 20, 23, 24, 25, 24, 23, 20, 17, 12, 7],
            [7, 13, 18, 22, 25, 27, 28, 28, 27, 25, 22, 18, 13, 7],
            [8, 14, 20, 24, 28, 30, 32, 32, 32, 30, 28, 24, 20, 14, 8],
            [8, 15, 21, 26, 30, 33, 35, 36, 36, 35, 33, 30, 26, 21, 15, 8],
            [9, 16, 23, 28, 33, 36, 39, 40, 41, 40, 39, 36, 33, 28, 23, 16, 9],
            [9, 17, 24, 30, 35, 39, 42, 44, 45, 45, 44, 42, 39, 35, 30, 24, 17, 9],
            [10, 18, 26, 32, 38, 42, 46, 48, 50, 50, 50, 48, 46, 42, 38, 32, 26, 18, 10],
            [10, 19, 27, 34, 40, 45, 49, 52, 54, 55, 55, 54, 52, 49, 45, 40, 34, 27, 19, 10],
            [11, 20, 29, 36, 43, 48, 53, 56, 59, 60, 61, 60, 59, 56, 53, 48, 43, 36, 29, 20, 11],
            [11, 21, 30, 38, 45, 51, 56, 60, 63, 65, 66, 66, 65, 63, 60, 56, 51, 45, 38, 30, 21, 11],
            [12, 22, 32, 40, 48, 54, 60, 64, 68, 70, 72, 72, 72, 70, 68, 64, 60, 54, 48, 40, 32, 22, 12],
            [12, 23, 33, 42, 50, 57, 63, 68, 72, 75, 77, 78, 78, 77, 75, 72, 68, 63, 57, 50, 42, 33, 23, 12],
            [13, 24, 35, 44, 53, 60, 67, 72, 77, 80, 83, 84, 85, 84, 83, 80, 77, 72, 67, 60, 53, 44, 35, 24, 13],
            [13, 25, 36, 46, 55, 63, 70, 76, 81, 85, 88, 90, 91, 91, 90, 88, 85, 81, 76, 70, 63, 55, 46, 36, 25, 13],
            [14, 26, 38, 48, 58, 66, 74, 80, 86, 90, 94, 96, 98, 98, 98, 96, 94, 90, 86, 80, 74, 66, 58, 48, 38, 26, 14],
            [14, 27, 39, 50, 60, 69, 77, 84, 90, 95, 99, 102, 104, 105, 105, 104, 102, 99, 95, 90, 84, 77, 69, 60, 50, 39, 27, 14],
            [15, 28, 41, 52, 63, 72, 81, 88, 95, 100, 105, 108, 111, 112, 113, 112, 111, 108, 105, 100, 95, 88, 81, 72, 63, 52, 41, 28, 15],
            [15, 29, 42, 54, 65, 75, 84, 92, 99, 105, 110, 114, 117, 119, 120, 120, 119, 117, 114, 110, 105, 99, 92, 84, 75, 65, 54, 42, 29, 15],
            [16, 30, 44, 56, 68, 78, 88, 96, 104, 110, 116, 120, 124, 126, 128, 128, 128, 126, 124, 120, 116, 110, 104, 96, 88, 78, 68, 56, 44, 30, 16],
            [16, 31, 45, 58, 70, 81, 91, 100, 108, 115, 121, 126, 130, 133, 135, 136, 136, 135, 133, 130, 126, 121, 115, 108, 100, 91, 81, 70, 58, 45, 31, 16],
            [17, 32, 47, 60, 73, 84, 95, 104, 113, 120, 127, 132, 137, 140, 143, 144, 145, 144, 143, 140, 137, 132, 127, 120, 113, 104, 95, 84, 73, 60, 47, 32, 17],
            [17, 33, 48, 62, 75, 87, 98, 108, 117, 125, 132, 138, 143, 147, 150, 152, 153, 153, 152, 150, 147, 143, 138, 132, 125, 117, 108, 98, 87, 75, 62, 48, 33, 17],
            [18, 34, 50, 64, 78, 90, 102, 112, 122, 130, 138, 144, 150, 154, 158, 160, 162, 162, 162, 160, 158, 154, 150, 144, 138, 130, 122, 112, 102, 90, 78, 64, 50, 34, 18],
            [18, 35, 51, 66, 80, 93, 105, 116, 126, 135, 143, 150, 156, 161, 165, 168, 170, 171, 171, 170, 168, 165, 161, 156, 150, 143, 135, 126, 116, 105, 93, 80, 66, 51, 35, 18],
            [19, 36, 53, 68, 83, 96, 109, 120, 131, 140, 149, 156, 163, 168, 173, 176, 179, 180, 181, 180, 179, 176, 173, 168, 163, 156, 149, 140, 131, 120, 109, 96, 83, 68, 53, 36, 19],
            [19, 37, 54, 70, 85, 99, 112, 124, 135, 145, 154, 162, 169, 175, 180, 184, 187, 189, 190, 190, 189, 187, 184, 180, 175, 169, 162, 154, 145, 135, 124, 112, 99, 85, 70, 54, 37, 19],
            [20, 38, 56, 72, 88, 102, 116, 128, 140, 150, 160, 168, 176, 182, 188, 192, 196, 198, 200, 200, 200, 198, 196, 192, 188, 182, 176, 168, 160, 150, 140, 128, 116, 102, 88, 72, 56, 38, 20],
            [20, 39, 57, 74, 90, 105, 119, 132, 144, 155, 165, 174, 182, 189, 195, 200, 204, 207, 209, 210, 210, 209, 207, 204, 200, 195, 189, 182, 174, 165, 155, 144, 132, 119, 105, 90, 74, 57, 39, 20],
            [21, 40, 59, 76, 93, 108, 123, 136, 149, 160, 171, 180, 189, 196, 203, 208, 213, 216, 219, 220, 221, 220, 219, 216, 213, 208, 203, 196, 189, 180, 171, 160, 149, 136, 123, 108, 93, 76, 59, 40, 21],
            [21, 41, 60, 78, 95, 111, 126, 140, 153, 165, 176, 186, 195, 203, 210, 216, 221, 225, 228, 230, 231, 231, 230, 228, 225, 221, 216, 210, 203, 195, 186, 176, 165, 153, 140, 126, 111, 95, 78, 60, 41, 21],
            [22, 42, 62, 80, 98, 114, 130, 144, 158, 170, 182, 192, 202, 210, 218, 224, 230, 234, 238, 240, 242, 242, 242, 240, 238, 234, 230, 224, 218, 210, 202, 192, 182, 170, 158, 144, 130, 114, 98, 80, 62, 42, 22],
            [22, 43, 63, 82, 100, 117, 133, 148, 162, 175, 187, 198, 208, 217, 225, 232, 238, 243, 247, 250, 252, 253, 253, 252, 250, 247, 243, 238, 232, 225, 217, 208, 198, 187, 175, 162, 148, 133, 117, 100, 82, 63, 43, 22],
            [23, 44, 65, 84, 103, 120, 137, 152, 167, 180, 193, 204, 215, 224, 233, 240, 247, 252, 257, 260, 263, 264, 265, 264, 263, 260, 257, 252, 247, 240, 233, 224, 215, 204, 193, 180, 167, 152, 137, 120, 103, 84, 65, 44, 23],
            [23, 45, 66, 86, 105, 123, 140, 156, 171, 185, 198, 210, 221, 231, 240, 248, 255, 261, 266, 270, 273, 275, 276, 276, 275, 273, 270, 266, 261, 255, 248, 240, 231, 221, 210, 198, 185, 171, 156, 140, 123, 105, 86, 66, 45, 23],
            [24, 46, 68, 88, 108, 126, 144, 160, 176, 190, 204, 216, 228, 238, 248, 256, 264, 270, 276, 280, 284, 286, 288, 288, 288, 286, 284, 280, 276, 270, 264, 256, 248, 238, 228, 216, 204, 190, 176, 160, 144, 126, 108, 88, 68, 46, 24],
            [24, 47, 69, 90, 110, 129, 147, 164, 180, 195, 209, 222, 234, 245, 255, 264, 272, 279, 285, 290, 294, 297, 299, 300, 300, 299, 297, 294, 290, 285, 279, 272, 264, 255, 245, 234, 222, 209, 195, 180, 164, 147, 129, 110, 90, 69, 47, 24],
            [25, 48, 71, 92, 113, 132, 151, 168, 185, 200, 215, 228, 241, 252, 263, 272, 281, 288, 295, 300, 305, 308, 311, 312, 313, 312, 311, 308, 305, 300, 295, 288, 281, 272, 263, 252, 241, 228, 215, 200, 185, 168, 151, 132, 113, 92, 71, 48, 25],
            [25, 49, 72, 94, 115, 135, 154, 172, 189, 205, 220, 234, 247, 259, 270, 280, 289, 297, 304, 310, 315, 319, 322, 324, 325, 325, 324, 322, 319, 315, 310, 304, 297, 289, 280, 270, 259, 247, 234, 220, 205, 189, 172, 154, 135, 115, 94, 72, 49, 25],
            [26, 50, 74, 96, 118, 138, 158, 176, 194, 210, 226, 240, 254, 266, 278, 288, 298, 306, 314, 320, 326, 330, 334, 336, 338, 338, 338, 336, 334, 330, 326, 320, 314, 306, 298, 288, 278, 266, 254, 240, 226, 210, 194, 176, 158, 138, 118, 96, 74, 50, 26],
            [26, 51, 75, 98, 120, 141, 161, 180, 198, 215, 231, 246, 260, 273, 285, 296, 306, 315, 323, 330, 336, 341, 345, 348, 350, 351, 351, 350, 348, 345, 341, 336, 330, 323, 315, 306, 296, 285, 273, 260, 246, 231, 215, 198, 180, 161, 141, 120, 98, 75, 51, 26],
            [27, 52, 77, 100, 123, 144, 165, 184, 203, 220, 237, 252, 267, 280, 293, 304, 315, 324, 333, 340, 347, 352, 357, 360, 363, 364, 365, 364, 363, 360, 357, 352, 347, 340, 333, 324, 315, 304, 293, 280, 267, 252, 237, 220, 203, 184, 165, 144, 123, 100, 77, 52, 27],
            [27, 53, 78, 102, 125, 147, 168, 188, 207, 225, 242, 258, 273, 287, 300, 312, 323, 333, 342, 350, 357, 363, 368, 372, 375, 377, 378, 378, 377, 375, 372, 368, 363, 357, 350, 342, 333, 323, 312, 300, 287, 273, 258, 242, 225, 207, 188, 168, 147, 125, 102, 78, 53, 27],
            [28, 54, 80, 104, 128, 150, 172, 192, 212, 230, 248, 264, 280, 294, 308, 320, 332, 342, 352, 360, 368, 374, 380, 384, 388, 390, 392, 392, 392, 390, 388, 384, 380, 374, 368, 360, 352, 342, 332, 320, 308, 294, 280, 264, 248, 230, 212, 192, 172, 150, 128, 104, 80, 54, 28],
            [28, 55, 81, 106, 130, 153, 175, 196, 216, 235, 253, 270, 286, 301, 315, 328, 340, 351, 361, 370, 378, 385, 391, 396, 400, 403, 405, 406, 406, 405, 403, 400, 396, 391, 385, 378, 370, 361, 351, 340, 328, 315, 301, 286, 270, 253, 235, 216, 196, 175, 153, 130, 106, 81, 55, 28],
            [29, 56, 83, 108, 133, 156, 179, 200, 221, 240, 259, 276, 293, 308, 323, 336, 349, 360, 371, 380, 389, 396, 403, 408, 413, 416, 419, 420, 421, 420, 419, 416, 413, 408, 403, 396, 389, 380, 371, 360, 349, 336, 323, 308, 293, 276, 259, 240, 221, 200, 179, 156, 133, 108, 83, 56, 29],
            [29, 57, 84, 110, 135, 159, 182, 204, 225, 245, 264, 282, 299, 315, 330, 344, 357, 369, 380, 390, 399, 407, 414, 420, 425, 429, 432, 434, 435, 435, 434, 432, 429, 425, 420, 414, 407, 399, 390, 380, 369, 357, 344, 330, 315, 299, 282, 264, 245, 225, 204, 182, 159, 135, 110, 84, 57, 29],
            [30, 58, 86, 112, 138, 162, 186, 208, 230, 250, 270, 288, 306, 322, 338, 352, 366, 378, 390, 400, 410, 418, 426, 432, 438, 442, 446, 448, 450, 450, 450, 448, 446, 442, 438, 432, 426, 418, 410, 400, 390, 378, 366, 352, 338, 322, 306, 288, 270, 250, 230, 208, 186, 162, 138, 112, 86, 58, 30],
            [30, 59, 87, 114, 140, 165, 189, 212, 234, 255, 275, 294, 312, 329, 345, 360, 374, 387, 399, 410, 420, 429, 437, 444, 450, 455, 459, 462, 464, 465, 465, 464, 462, 459, 455, 450, 444, 437, 429, 420, 410, 399, 387, 374, 360, 345, 329, 312, 294, 275, 255, 234, 212, 189, 165, 140, 114, 87, 59, 30],
            [31, 60, 89, 116, 143, 168, 193, 216, 239, 260, 281, 300, 319, 336, 353, 368, 383, 396, 409, 420, 431, 440, 449, 456, 463, 468, 473, 476, 479, 480, 481, 480, 479, 476, 473, 468, 463, 456, 449, 440, 431, 420, 409, 396, 383, 368, 353, 336, 319, 300, 281, 260, 239, 216, 193, 168, 143, 116, 89, 60, 31],
            [31, 61, 90, 118, 145, 171, 196, 220, 243, 265, 286, 306, 325, 343, 360, 376, 391, 405, 418, 430, 441, 451, 460, 468, 475, 481, 486, 490, 493, 495, 496, 496, 495, 493, 490, 486, 481, 475, 468, 460, 451, 441, 430, 418, 405, 391, 376, 360, 343, 325, 306, 286, 265, 243, 220, 196, 171, 145, 118, 90, 61, 31],
            [32, 62, 92, 120, 148, 174, 200, 224, 248, 270, 292, 312, 332, 350, 368, 384, 400, 414, 428, 440, 452, 462, 472, 480, 488, 494, 500, 504, 508, 510, 512, 512, 512, 510, 508, 504, 500, 494, 488, 480, 472, 462, 452, 440, 428, 414, 400, 384, 368, 350, 332, 312, 292, 270, 248, 224, 200, 174, 148, 120, 92, 62, 32],
            [32, 63, 93, 122, 150, 177, 203, 228, 252, 275, 297, 318, 338, 357, 375, 392, 408, 423, 437, 450, 462, 473, 483, 492, 500, 507, 513, 518, 522, 525, 527, 528, 528, 527, 525, 522, 518, 513, 507, 500, 492, 483, 473, 462, 450, 437, 423, 408, 392, 375, 357, 338, 318, 297, 275, 252, 228, 203, 177, 150, 122, 93, 63, 32],
            [33, 64, 95, 124, 153, 180, 207, 232, 257, 280, 303, 324, 345, 364, 383, 400, 417, 432, 447, 460, 473, 484, 495, 504, 513, 520, 527, 532, 537, 540, 543, 544, 545, 544, 543, 540, 537, 532, 527, 520, 513, 504, 495, 484, 473, 460, 447, 432, 417, 400, 383, 364, 345, 324, 303, 280, 257, 232, 207, 180, 153, 124, 95, 64, 33],
            [33, 65, 96, 126, 155, 183, 210, 236, 261, 285, 308, 330, 351, 371, 390, 408, 425, 441, 456, 470, 483, 495, 506, 516, 525, 533, 540, 546, 551, 555, 558, 560, 561, 561, 560, 558, 555, 551, 546, 540, 533, 525, 516, 506, 495, 483, 470, 456, 441, 425, 408, 390, 371, 351, 330, 308, 285, 261, 236, 210, 183, 155, 126, 96, 65, 33],
            [34, 66, 98, 128, 158, 186, 214, 240, 266, 290, 314, 336, 358, 378, 398, 416, 434, 450, 466, 480, 494, 506, 518, 528, 538, 546, 554, 560, 566, 570, 574, 576, 578, 578, 578, 576, 574, 570, 566, 560, 554, 546, 538, 528, 518, 506, 494, 480, 466, 450, 434, 416, 398, 378, 358, 336, 314, 290, 266, 240, 214, 186, 158, 128, 98, 66, 34],
            [34, 67, 99, 130, 160, 189, 217, 244, 270, 295, 319, 342, 364, 385, 405, 424, 442, 459, 475, 490, 504, 517, 529, 540, 550, 559, 567, 574, 580, 585, 589, 592, 594, 595, 595, 594, 592, 589, 585, 580, 574, 567, 559, 550, 540, 529, 517, 504, 490, 475, 459, 442, 424, 405, 385, 364, 342, 319, 295, 270, 244, 217, 189, 160, 130, 99, 67, 34],
            [35, 68, 101, 132, 163, 192, 221, 248, 275, 300, 325, 348, 371, 392, 413, 432, 451, 468, 485, 500, 515, 528, 541, 552, 563, 572, 581, 588, 595, 600, 605, 608, 611, 612, 613, 612, 611, 608, 605, 600, 595, 588, 581, 572, 563, 552, 541, 528, 515, 500, 485, 468, 451, 432, 413, 392, 371, 348, 325, 300, 275, 248, 221, 192, 163, 132, 101, 68, 35],
            [35, 69, 102, 134, 165, 195, 224, 252, 279, 305, 330, 354, 377, 399, 420, 440, 459, 477, 494, 510, 525, 539, 552, 564, 575, 585, 594, 602, 609, 615, 620, 624, 627, 629, 630, 630, 629, 627, 624, 620, 615, 609, 602, 594, 585, 575, 564, 552, 539, 525, 510, 494, 477, 459, 440, 420, 399, 377, 354, 330, 305, 279, 252, 224, 195, 165, 134, 102, 69, 35],
            [36, 70, 104, 136, 168, 198, 228, 256, 284, 310, 336, 360, 384, 406, 428, 448, 468, 486, 504, 520, 536, 550, 564, 576, 588, 598, 608, 616, 624, 630, 636, 640, 644, 646, 648, 648, 648, 646, 644, 640, 636, 630, 624, 616, 608, 598, 588, 576, 564, 550, 536, 520, 504, 486, 468, 448, 428, 406, 384, 360, 336, 310, 284, 256, 228, 198, 168, 136, 104, 70, 36],
            [36, 71, 105, 138, 170, 201, 231, 260, 288, 315, 341, 366, 390, 413, 435, 456, 476, 495, 513, 530, 546, 561, 575, 588, 600, 611, 621, 630, 638, 645, 651, 656, 660, 663, 665, 666, 666, 665, 663, 660, 656, 651, 645, 638, 630, 621, 611, 600, 588, 575, 561, 546, 530, 513, 495, 476, 456, 435, 413, 390, 366, 341, 315, 288, 260, 231, 201, 170, 138, 105, 71, 36],
            [37, 72, 107, 140, 173, 204, 235, 264, 293, 320, 347, 372, 397, 420, 443, 464, 485, 504, 523, 540, 557, 572, 587, 600, 613, 624, 635, 644, 653, 660, 667, 672, 677, 680, 683, 684, 685, 684, 683, 680, 677, 672, 667, 660, 653, 644, 635, 624, 613, 600, 587, 572, 557, 540, 523, 504, 485, 464, 443, 420, 397, 372, 347, 320, 293, 264, 235, 204, 173, 140, 107, 72, 37],
            [37, 73, 108, 142, 175, 207, 238, 268, 297, 325, 352, 378, 403, 427, 450, 472, 493, 513, 532, 550, 567, 583, 598, 612, 625, 637, 648, 658, 667, 675, 682, 688, 693, 697, 700, 702, 703, 703, 702, 700, 697, 693, 688, 682, 675, 667, 658, 648, 637, 625, 612, 598, 583, 567, 550, 532, 513, 493, 472, 450, 427, 403, 378, 352, 325, 297, 268, 238, 207, 175, 142, 108, 73, 37],
            [38, 74, 110, 144, 178, 210, 242, 272, 302, 330, 358, 384, 410, 434, 458, 480, 502, 522, 542, 560, 578, 594, 610, 624, 638, 650, 662, 672, 682, 690, 698, 704, 710, 714, 718, 720, 722, 722, 722, 720, 718, 714, 710, 704, 698, 690, 682, 672, 662, 650, 638, 624, 610, 594, 578, 560, 542, 522, 502, 480, 458, 434, 410, 384, 358, 330, 302, 272, 242, 210, 178, 144, 110, 74, 38],
            [38, 75, 111, 146, 180, 213, 245, 276, 306, 335, 363, 390, 416, 441, 465, 488, 510, 531, 551, 570, 588, 605, 621, 636, 650, 663, 675, 686, 696, 705, 713, 720, 726, 731, 735, 738, 740, 741, 741, 740, 738, 735, 731, 726, 720, 713, 705, 696, 686, 675, 663, 650, 636, 621, 605, 588, 570, 551, 531, 510, 488, 465, 441, 416, 390, 363, 335, 306, 276, 245, 213, 180, 146, 111, 75, 38],
            [39, 76, 113, 148, 183, 216, 249, 280, 311, 340, 369, 396, 423, 448, 473, 496, 519, 540, 561, 580, 599, 616, 633, 648, 663, 676, 689, 700, 711, 720, 729, 736, 743, 748, 753, 756, 759, 760, 761, 760, 759, 756, 753, 748, 743, 736, 729, 720, 711, 700, 689, 676, 663, 648, 633, 616, 599, 580, 561, 540, 519, 496, 473, 448, 423, 396, 369, 340, 311, 280, 249, 216, 183, 148, 113, 76, 39],
            [39, 77, 114, 150, 185, 219, 252, 284, 315, 345, 374, 402, 429, 455, 480, 504, 527, 549, 570, 590, 609, 627, 644, 660, 675, 689, 702, 714, 725, 735, 744, 752, 759, 765, 770, 774, 777, 779, 780, 780, 779, 777, 774, 770, 765, 759, 752, 744, 735, 725, 714, 702, 689, 675, 660, 644, 627, 609, 590, 570, 549, 527, 504, 480, 455, 429, 402, 374, 345, 315, 284, 252, 219, 185, 150, 114, 77, 39],
            [40, 78, 116, 152, 188, 222, 256, 288, 320, 350, 380, 408, 436, 462, 488, 512, 536, 558, 580, 600, 620, 638, 656, 672, 688, 702, 716, 728, 740, 750, 760, 768, 776, 782, 788, 792, 796, 798, 800, 800, 800, 798, 796, 792, 788, 782, 776, 768, 760, 750, 740, 728, 716, 702, 688, 672, 656, 638, 620, 600, 580, 558, 536, 512, 488, 462, 436, 408, 380, 350, 320, 288, 256, 222, 188, 152, 116, 78, 40],
            [40, 79, 117, 154, 190, 225, 259, 292, 324, 355, 385, 414, 442, 469, 495, 520, 544, 567, 589, 610, 630, 649, 667, 684, 700, 715, 729, 742, 754, 765, 775, 784, 792, 799, 805, 810, 814, 817, 819, 820, 820, 819, 817, 814, 810, 805, 799, 792, 784, 775, 765, 754, 742, 729, 715, 700, 684, 667, 649, 630, 610, 589, 567, 544, 520, 495, 469, 442, 414, 385, 355, 324, 292, 259, 225, 190, 154, 117, 79, 40],
            [41, 80, 119, 156, 193, 228, 263, 296, 329, 360, 391, 420, 449, 476, 503, 528, 553, 576, 599, 620, 641, 660, 679, 696, 713, 728, 743, 756, 769, 780, 791, 800, 809, 816, 823, 828, 833, 836, 839, 840, 841, 840, 839, 836, 833, 828, 823, 816, 809, 800, 791, 780, 769, 756, 743, 728, 713, 696, 679, 660, 641, 620, 599, 576, 553, 528, 503, 476, 449, 420, 391, 360, 329, 296, 263, 228, 193, 156, 119, 80, 41],
            [41, 81, 120, 158, 195, 231, 266, 300, 333, 365, 396, 426, 455, 483, 510, 536, 561, 585, 608, 630, 651, 671, 690, 708, 725, 741, 756, 770, 783, 795, 806, 816, 825, 833, 840, 846, 851, 855, 858, 860, 861, 861, 860, 858, 855, 851, 846, 840, 833, 825, 816, 806, 795, 783, 770, 756, 741, 725, 708, 690, 671, 651, 630, 608, 585, 561, 536, 510, 483, 455, 426, 396, 365, 333, 300, 266, 231, 195, 158, 120, 81, 41],
            [42, 82, 122, 160, 198, 234, 270, 304, 338, 370, 402, 432, 462, 490, 518, 544, 570, 594, 618, 640, 662, 682, 702, 720, 738, 754, 770, 784, 798, 810, 822, 832, 842, 850, 858, 864, 870, 874, 878, 880, 882, 882, 882, 880, 878, 874, 870, 864, 858, 850, 842, 832, 822, 810, 798, 784, 770, 754, 738, 720, 702, 682, 662, 640, 618, 594, 570, 544, 518, 490, 462, 432, 402, 370, 338, 304, 270, 234, 198, 160, 122, 82, 42],
            [42, 83, 123, 162, 200, 237, 273, 308, 342, 375, 407, 438, 468, 497, 525, 552, 578, 603, 627, 650, 672, 693, 713, 732, 750, 767, 783, 798, 812, 825, 837, 848, 858, 867, 875, 882, 888, 893, 897, 900, 902, 903, 903, 902, 900, 897, 893, 888, 882, 875, 867, 858, 848, 837, 825, 812, 798, 783, 767, 750, 732, 713, 693, 672, 650, 627, 603, 578, 552, 525, 497, 468, 438, 407, 375, 342, 308, 273, 237, 200, 162, 123, 83, 42],
            [43, 84, 125, 164, 203, 240, 277, 312, 347, 380, 413, 444, 475, 504, 533, 560, 587, 612, 637, 660, 683, 704, 725, 744, 763, 780, 797, 812, 827, 840, 853, 864, 875, 884, 893, 900, 907, 912, 917, 920, 923, 924, 925, 924, 923, 920, 917, 912, 907, 900, 893, 884, 875, 864, 853, 840, 827, 812, 797, 780, 763, 744, 725, 704, 683, 660, 637, 612, 587, 560, 533, 504, 475, 444, 413, 380, 347, 312, 277, 240, 203, 164, 125, 84, 43],
            [43, 85, 126, 166, 205, 243, 280, 316, 351, 385, 418, 450, 481, 511, 540, 568, 595, 621, 646, 670, 693, 715, 736, 756, 775, 793, 810, 826, 841, 855, 868, 880, 891, 901, 910, 918, 925, 931, 936, 940, 943, 945, 946, 946, 945, 943, 940, 936, 931, 925, 918, 910, 901, 891, 880, 868, 855, 841, 826, 810, 793, 775, 756, 736, 715, 693, 670, 646, 621, 595, 568, 540, 511, 481, 450, 418, 385, 351, 316, 280, 243, 205, 166, 126, 85, 43],
            [44, 86, 128, 168, 208, 246, 284, 320, 356, 390, 424, 456, 488, 518, 548, 576, 604, 630, 656, 680, 704, 726, 748, 768, 788, 806, 824, 840, 856, 870, 884, 896, 908, 918, 928, 936, 944, 950, 956, 960, 964, 966, 968, 968, 968, 966, 964, 960, 956, 950, 944, 936, 928, 918, 908, 896, 884, 870, 856, 840, 824, 806, 788, 768, 748, 726, 704, 680, 656, 630, 604, 576, 548, 518, 488, 456, 424, 390, 356, 320, 284, 246, 208, 168, 128, 86, 44],
            [44, 87, 129, 170, 210, 249, 287, 324, 360, 395, 429, 462, 494, 525, 555, 584, 612, 639, 665, 690, 714, 737, 759, 780, 800, 819, 837, 854, 870, 885, 899, 912, 924, 935, 945, 954, 962, 969, 975, 980, 984, 987, 989, 990, 990, 989, 987, 984, 980, 975, 969, 962, 954, 945, 935, 924, 912, 899, 885, 870, 854, 837, 819, 800, 780, 759, 737, 714, 690, 665, 639, 612, 584, 555, 525, 494, 462, 429, 395, 360, 324, 287, 249, 210, 170, 129, 87, 44],
            [45, 88, 131, 172, 213, 252, 291, 328, 365, 400, 435, 468, 501, 532, 563, 592, 621, 648, 675, 700, 725, 748, 771, 792, 813, 832, 851, 868, 885, 900, 915, 928, 941, 952, 963, 972, 981, 988, 995, 1000, 1005, 1008, 1011, 1012, 1013, 1012, 1011, 1008, 1005, 1000, 995, 988, 981, 972, 963, 952, 941, 928, 915, 900, 885, 868, 851, 832, 813, 792, 771, 748, 725, 700, 675, 648, 621, 592, 563, 532, 501, 468, 435, 400, 365, 328, 291, 252, 213, 172, 131, 88, 45],
            [45, 89, 132, 174, 215, 255, 294, 332, 369, 405, 440, 474, 507, 539, 570, 600, 629, 657, 684, 710, 735, 759, 782, 804, 825, 845, 864, 882, 899, 915, 930, 944, 957, 969, 980, 990, 999, 1007, 1014, 1020, 1025, 1029, 1032, 1034, 1035, 1035, 1034, 1032, 1029, 1025, 1020, 1014, 1007, 999, 990, 980, 969, 957, 944, 930, 915, 899, 882, 864, 845, 825, 804, 782, 759, 735, 710, 684, 657, 629, 600, 570, 539, 507, 474, 440, 405, 369, 332, 294, 255, 215, 174, 132, 89, 45],
            [46, 90, 134, 176, 218, 258, 298, 336, 374, 410, 446, 480, 514, 546, 578, 608, 638, 666, 694, 720, 746, 770, 794, 816, 838, 858, 878, 896, 914, 930, 946, 960, 974, 986, 998, 1008, 1018, 1026, 1034, 1040, 1046, 1050, 1054, 1056, 1058, 1058, 1058, 1056, 1054, 1050, 1046, 1040, 1034, 1026, 1018, 1008, 998, 986, 974, 960, 946, 930, 914, 896, 878, 858, 838, 816, 794, 770, 746, 720, 694, 666, 638, 608, 578, 546, 514, 480, 446, 410, 374, 336, 298, 258, 218, 176, 134, 90, 46],
            [46, 91, 135, 178, 220, 261, 301, 340, 378, 415, 451, 486, 520, 553, 585, 616, 646, 675, 703, 730, 756, 781, 805, 828, 850, 871, 891, 910, 928, 945, 961, 976, 990, 1003, 1015, 1026, 1036, 1045, 1053, 1060, 1066, 1071, 1075, 1078, 1080, 1081, 1081, 1080, 1078, 1075, 1071, 1066, 1060, 1053, 1045, 1036, 1026, 1015, 1003, 990, 976, 961, 945, 928, 910, 891, 871, 850, 828, 805, 781, 756, 730, 703, 675, 646, 616, 585, 553, 520, 486, 451, 415, 378, 340, 301, 261, 220, 178, 135, 91, 46],
            [47, 92, 137, 180, 223, 264, 305, 344, 383, 420, 457, 492, 527, 560, 593, 624, 655, 684, 713, 740, 767, 792, 817, 840, 863, 884, 905, 924, 943, 960, 977, 992, 1007, 1020, 1033, 1044, 1055, 1064, 1073, 1080, 1087, 1092, 1097, 1100, 1103, 1104, 1105, 1104, 1103, 1100, 1097, 1092, 1087, 1080, 1073, 1064, 1055, 1044, 1033, 1020, 1007, 992, 977, 960, 943, 924, 905, 884, 863, 840, 817, 792, 767, 740, 713, 684, 655, 624, 593, 560, 527, 492, 457, 420, 383, 344, 305, 264, 223, 180, 137, 92, 47],
            [47, 93, 138, 182, 225, 267, 308, 348, 387, 425, 462, 498, 533, 567, 600, 632, 663, 693, 722, 750, 777, 803, 828, 852, 875, 897, 918, 938, 957, 975, 992, 1008, 1023, 1037, 1050, 1062, 1073, 1083, 1092, 1100, 1107, 1113, 1118, 1122, 1125, 1127, 1128, 1128, 1127, 1125, 1122, 1118, 1113, 1107, 1100, 1092, 1083, 1073, 1062, 1050, 1037, 1023, 1008, 992, 975, 957, 938, 918, 897, 875, 852, 828, 803, 777, 750, 722, 693, 663, 632, 600, 567, 533, 498, 462, 425, 387, 348, 308, 267, 225, 182, 138, 93, 47],
            [48, 94, 140, 184, 228, 270, 312, 352, 392, 430, 468, 504, 540, 574, 608, 640, 672, 702, 732, 760, 788, 814, 840, 864, 888, 910, 932, 952, 972, 990, 1008, 1024, 1040, 1054, 1068, 1080, 1092, 1102, 1112, 1120, 1128, 1134, 1140, 1144, 1148, 1150, 1152, 1152, 1152, 1150, 1148, 1144, 1140, 1134, 1128, 1120, 1112, 1102, 1092, 1080, 1068, 1054, 1040, 1024, 1008, 990, 972, 952, 932, 910, 888, 864, 840, 814, 788, 760, 732, 702, 672, 640, 608, 574, 540, 504, 468, 430, 392, 352, 312, 270, 228, 184, 140, 94, 48],
            [48, 95, 141, 186, 230, 273, 315, 356, 396, 435, 473, 510, 546, 581, 615, 648, 680, 711, 741, 770, 798, 825, 851, 876, 900, 923, 945, 966, 986, 1005, 1023, 1040, 1056, 1071, 1085, 1098, 1110, 1121, 1131, 1140, 1148, 1155, 1161, 1166, 1170, 1173, 1175, 1176, 1176, 1175, 1173, 1170, 1166, 1161, 1155, 1148, 1140, 1131, 1121, 1110, 1098, 1085, 1071, 1056, 1040, 1023, 1005, 986, 966, 945, 923, 900, 876, 851, 825, 798, 770, 741, 711, 680, 648, 615, 581, 546, 510, 473, 435, 396, 356, 315, 273, 230, 186, 141, 95, 48],
            [49, 96, 143, 188, 233, 276, 319, 360, 401, 440, 479, 516, 553, 588, 623, 656, 689, 720, 751, 780, 809, 836, 863, 888, 913, 936, 959, 980, 1001, 1020, 1039, 1056, 1073, 1088, 1103, 1116, 1129, 1140, 1151, 1160, 1169, 1176, 1183, 1188, 1193, 1196, 1199, 1200, 1201, 1200, 1199, 1196, 1193, 1188, 1183, 1176, 1169, 1160, 1151, 1140, 1129, 1116, 1103, 1088, 1073, 1056, 1039, 1020, 1001, 980, 959, 936, 913, 888, 863, 836, 809, 780, 751, 720, 689, 656, 623, 588, 553, 516, 479, 440, 401, 360, 319, 276, 233, 188, 143, 96, 49],
            [49, 97, 144, 190, 235, 279, 322, 364, 405, 445, 484, 522, 559, 595, 630, 664, 697, 729, 760, 790, 819, 847, 874, 900, 925, 949, 972, 994, 1015, 1035, 1054, 1072, 1089, 1105, 1120, 1134, 1147, 1159, 1170, 1180, 1189, 1197, 1204, 1210, 1215, 1219, 1222, 1224, 1225, 1225, 1224, 1222, 1219, 1215, 1210, 1204, 1197, 1189, 1180, 1170, 1159, 1147, 1134, 1120, 1105, 1089, 1072, 1054, 1035, 1015, 994, 972, 949, 925, 900, 874, 847, 819, 790, 760, 729, 697, 664, 630, 595, 559, 522, 484, 445, 405, 364, 322, 279, 235, 190, 144, 97, 49],
            [50, 98, 146, 192, 238, 282, 326, 368, 410, 450, 490, 528, 566, 602, 638, 672, 706, 738, 770, 800, 830, 858, 886, 912, 938, 962, 986, 1008, 1030, 1050, 1070, 1088, 1106, 1122, 1138, 1152, 1166, 1178, 1190, 1200, 1210, 1218, 1226, 1232, 1238, 1242, 1246, 1248, 1250, 1250, 1250, 1248, 1246, 1242, 1238, 1232, 1226, 1218, 1210, 1200, 1190, 1178, 1166, 1152, 1138, 1122, 1106, 1088, 1070, 1050, 1030, 1008, 986, 962, 938, 912, 886, 858, 830, 800, 770, 738, 706, 672, 638, 602, 566, 528, 490, 450, 410, 368, 326, 282, 238, 192, 146, 98, 50],
            [50, 99, 147, 194, 240, 285, 329, 372, 414, 455, 495, 534, 572, 609, 645, 680, 714, 747, 779, 810, 840, 869, 897, 924, 950, 975, 999, 1022, 1044, 1065, 1085, 1104, 1122, 1139, 1155, 1170, 1184, 1197, 1209, 1220, 1230, 1239, 1247, 1254, 1260, 1265, 1269, 1272, 1274, 1275, 1275, 1274, 1272, 1269, 1265, 1260, 1254, 1247, 1239, 1230, 1220, 1209, 1197, 1184, 1170, 1155, 1139, 1122, 1104, 1085, 1065, 1044, 1022, 999, 975, 950, 924, 897, 869, 840, 810, 779, 747, 714, 680, 645, 609, 572, 534, 495, 455, 414, 372, 329, 285, 240, 194, 147, 99, 50]
        ]
    def sumOddLengthSubarrays(self, arr: [int]) -> int:
        '''
        Naive On
        '''
        n = len(arr)
        times = self.cao[n]
        # print(times)
        return sum([times[i]*arr[i] for i in range(n)])
    def sumOddLengthSubarrays2(self, arr: [int]) -> int:
        '''
        Optimize On
        '''
        n = len(arr)
        ans = 0
        for i in range(n):
            left_nums = i+1
            right_nums = n-i
            l_odd_choices = left_nums//2
            l_even_choices = (left_nums+1)//2
            r_odd_choices = right_nums//2
            r_even_choices = (right_nums+1)//2
            ans += (l_odd_choices*r_odd_choices + l_even_choices*r_even_choices)*arr[i]
        return ans
        #     j = 3
        #     while i+j<=n:
        #         for k in range(i, i+j):
        #             times[k] += 1
        #         j += 2
        # print(times)
        # return sum([times[i]*arr[i] for i in range(n)])
s = Solution()
s.sumOddLengthSubarrays([0]*100)
# for i in range(100):
#     s.sumOddLengthSubarrays([0]*i)
cao = [1,4,2,5,3,3,2,4,5,6,7]
print(s.sumOddLengthSubarrays(
    cao
), s.sumOddLengthSubarrays2(
    cao
))