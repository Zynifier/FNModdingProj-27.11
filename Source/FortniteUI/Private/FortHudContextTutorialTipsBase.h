// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Math/MathFwd.h"
#include "Types/SlateEnums.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHudContextTutorialTipsBase.generated.h"

class UCanvasPanel;
class UCommonActionWidget;
class UFortHudContextTutorialIndicatorBall;
class UFortRichTextBlockKeybind;
class UOverlay;

UENUM(BlueprintType)
enum class EContextPositionPlatform : uint8
{
	NonMobile = 0,
	Mobile = 1,
};

USTRUCT(BlueprintType)
struct FContextPosition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ContextPosition")
	EContextPositionPlatform Platform;

	UPROPERTY(EditAnywhere, Category="ContextPosition")
	FVector2D Position;

	UPROPERTY(EditAnywhere, Category="ContextPosition")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	UPROPERTY(EditAnywhere, Category="ContextPosition")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortHudContextTutorialTipsBase : public UCommonActivatableWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnButtonCloseImplementation();

	UFUNCTION(BlueprintImplementableEvent)
	void OnButtonCloseProgressImplementation(float Progress);

	UFUNCTION(BlueprintCallable)
	void RegisterCloseButtonInput();

	UFUNCTION(BlueprintCallable)
	void SetDefaultPlatformPosition();

	UFUNCTION(BlueprintCallable)
	void SetPosition(const FVector2D Position, const EHorizontalAlignment HorizontalAlignment, const EVerticalAlignment VerticalAlignment);

	UFUNCTION(BlueprintCallable)
	void StartLerpContextTutorialBall(const int32 InPlayerID, const int32 InInstanceID, const float TotalTime, const float StartDelay);

	UFUNCTION(BlueprintImplementableEvent)
	void StartWorldMarkerIntroAnimation();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void StartWorldMarkerOutroAnimation(int32 InPlayerID, int32 InInstanceID) const;

	UFUNCTION(BlueprintImplementableEvent)
	void StopIntroAnimation();

	UFUNCTION(BlueprintCallable)
	void UnregisterCloseButtonInput();

	UPROPERTY(EditAnywhere, Category="Context Tutorial")
	TArray<FContextPosition> PositionPerPlatform;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCanvasPanel> CanvasPanel_Container;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCanvasPanel> CanvasPanel_Ball;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHudContextTutorialTipsBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Container;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHudContextTutorialIndicatorBall> ContextTutorialBall;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHudContextTutorialIndicatorBall> ContextTutorialBallParented;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHudContextTutorialTipsBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> TipActionWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHudContextTutorialTipsBase", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortRichTextBlockKeybind> RichTextBlock_Message;

	UPROPERTY(EditAnywhere, Category="FortHudContextTutorialTipsBase")
	float MaxLerpSpeedPercentPerSecond;

	UPROPERTY(EditAnywhere, Category="FortHudContextTutorialTipsBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CloseObjectInputAction;

	UPROPERTY(EditAnywhere, Category="FortHudContextTutorialTipsBase")
	float UpdateWorldMarkersInterval;

};

