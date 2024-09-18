import matplotlib.pyplot as plt

# 生成数据
spwmWave = [0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 4, 5, 6, 7, 7, 8,
	9, 10, 11, 12, 13, 14, 15, 17, 18, 19, 20, 22, 23, 24, 26, 27, 28, 30, 31, 33,
	34, 36, 37, 39, 40, 42, 44, 45, 47, 48, 50, 51, 53, 55, 56, 58, 59, 61, 62, 64,
	65, 67, 68, 70, 71, 73, 74, 75, 77, 78, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89,
	90, 91, 92, 93, 94, 94, 95, 96, 96, 97, 97, 98, 98, 98, 99, 99, 99, 99, 99, 99,
	99, 99, 99, 99, 99, 99, 98, 98, 98, 97, 97, 96, 96, 95, 94, 94, 93, 92, 91, 90,
	89, 88, 87, 86, 85, 84, 83, 82, 81, 79, 78, 77, 75, 74, 73, 71, 70, 68, 67, 65,
	64, 62, 61, 59, 58, 56, 55, 53, 51, 50, 48, 47, 45, 44, 42, 40, 39, 37, 36, 34,
	33, 31, 30, 28, 27, 26, 24, 23, 22, 20, 19, 18, 17, 15, 14, 13, 12, 11, 10, 9,
	8, 7, 7, 6, 5, 4, 4, 3, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0]

npwmWave = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 
 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 
 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 
 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 
 93, 94, 95, 96, 97, 98, 99, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80,
 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60,
 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40,
 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

# X轴
index1 = range(len(spwmWave))
index2 = range(len(npwmWave))

# 创建图形
fig, ax = plt.subplots(figsize=(10, 5))
ax.plot(index1, spwmWave, marker='.', label='Step SPWM Wave')  # 添加标签
ax.plot(index2, npwmWave, marker='.', label='Step NPWM Wave')  # 添加标签
ax.set_title('Step SPWM Waveform')
ax.set_xlabel('Index')
ax.set_ylabel('Value')
ax.grid(True)
ax.legend()  # 显示图例

# 用于显示文本的注释
annotation = ax.annotate("", xy=(0,0), xytext=(20,20),
                         textcoords="offset points",
                         bbox=dict(boxstyle="round", fc="w"),
                         arrowprops=dict(arrowstyle="->"))
annotation.set_visible(False)

# 鼠标移动事件
def on_mouse_move(event):
    if event.inaxes == ax:  # 检查鼠标是否在图形区域内
        # 获取最近的点
        x = int(event.xdata)
        if 0 <= x < len(spwmWave):
            y = spwmWave[x]
            annotation.xy = (x, y)
            annotation.set_text(f'SPWM - Index: {x}, Value: {y}')  # 显示 x 和 y 值
            annotation.set_visible(True)
            fig.canvas.draw_idle()
        elif 0 <= x < len(npwmWave):
            y = npwmWave[x]
            annotation.xy = (x, y)
            annotation.set_text(f'NPWM - Index: {x}, Value: {y}')  # 显示 x 和 y 值
            annotation.set_visible(True)
            fig.canvas.draw_idle()
        else:
            annotation.set_visible(False)
            fig.canvas.draw_idle()

# 连接事件
fig.canvas.mpl_connect("motion_notify_event", on_mouse_move)

# 显示图形
plt.show()