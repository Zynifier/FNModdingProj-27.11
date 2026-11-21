// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "InputCoreTypes.h"
#include "Styling/SlateTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "ImGuiModuleSettings.generated.h"

UENUM(BlueprintType)
enum class EImGuiCanvasSizeType : uint8
{
	/** Canvas will have a custom width and height. */
	Custom = 0,
	/** Canvas will have the same width and height as the desktop. */
	Desktop = 1,
	/** Canvas will always have the same width and height as the viewport. */
	Viewport = 2,
};

UENUM(BlueprintType)
enum class EImGuiDPIScaleMethod : uint8
{
	/** Scale ImGui fonts and styles. */
	ImGui = 0 UMETA(DisplayName="ImGui"),
	/** Scale in Slate. ImGui canvas size will be adjusted to get the screen size that is the same as defined in the Canvas Size property. */
	Slate = 1,
};

USTRUCT()
struct FImGuiCanvasSizeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Canvas Size")
	EImGuiCanvasSizeType SizeType;

	UPROPERTY(EditAnywhere, Category="Canvas Size", meta=(ClampMin="0", UIMin="0"))
	int32 Width;

	UPROPERTY(EditAnywhere, Category="Canvas Size", meta=(ClampMin="0", UIMin="0"))
	int32 Height;

	UPROPERTY(EditAnywhere, Category="Canvas Size", meta=(ClampMin="0", UIMin="0"))
	bool bExtendToViewport;

};

USTRUCT()
struct FImGuiDPIScaleInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="DPI Scale")
	EImGuiDPIScaleMethod ScalingMethod;

	UPROPERTY(EditAnywhere, Category="DPI Scale", meta=(ClampMin="0", UIMin="0"))
	float Scale;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scale", meta=(EditCondition="bScaleWithCurve", XAxisName="Resolution Height", YAxisName="Scale"))
	FRuntimeFloatCurve DPICurve;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scale")
	bool bScaleWithCurve;

};

USTRUCT()
struct FImGuiKeyInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Input")
	FKey Key;

	UPROPERTY(EditAnywhere, Category="Input")
	ECheckBoxState Shift;

	UPROPERTY(EditAnywhere, Category="Input")
	ECheckBoxState Ctrl;

	UPROPERTY(EditAnywhere, Category="Input")
	ECheckBoxState Alt;

	UPROPERTY(EditAnywhere, Category="Input")
	ECheckBoxState Cmd;

};

UCLASS(Config=ImGui, DefaultConfig)
class UImGuiSettings : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Config, Category="Extensions", meta=(MetaClass="/Script/ImGui.ImGuiInputHandler"))
	FSoftClassPath ImGuiInputHandlerClass;

	UPROPERTY(EditAnywhere, Config, Category="Input")
	bool bShareKeyboardInput;

	UPROPERTY(EditAnywhere, Config, Category="Input")
	bool bShareGamepadInput;

	UPROPERTY(EditAnywhere, Config, Category="Input")
	bool bShareMouseInput;

	UPROPERTY(EditAnywhere, Config, AdvancedDisplay, Category="Input")
	bool bUseSoftwareCursor;

	UPROPERTY(EditAnywhere, Config, Category="Keyboard Shortcuts")
	FImGuiKeyInfo ToggleInput;

	UPROPERTY(EditAnywhere, Config, Category="Controller Shortcuts")
	FImGuiKeyInfo ToggleInputController;

	UPROPERTY(EditAnywhere, Config, Category="Canvas Size")
	FImGuiCanvasSizeInfo CanvasSize;

	UPROPERTY(EditAnywhere, Config, Category="DPI Scale", meta=(ShowOnlyInnerProperties))
	FImGuiDPIScaleInfo DPIScale;

};

