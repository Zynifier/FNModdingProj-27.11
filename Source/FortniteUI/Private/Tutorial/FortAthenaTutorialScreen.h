// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "FortAthenaTutorialScreen.generated.h"

class UCommonWidgetSwitcherLegacy;
class UFortAthenaTutorialBaseInteraction;
class UUserWidget;

UENUM(BlueprintType)
enum class EHighlightType : uint8
{
	ESquareHighlight = 0 UMETA(DisplayName=" Square"),
	ECircleHighlight_Big = 1 UMETA(DisplayName=" Circle_Big"),
	ECircleHighlight_Small = 2 UMETA(DisplayName=" Circle_Small"),
};

UCLASS(meta=(DisableNativeTick))
class UFortAthenaTutorialScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaTutorialScreen(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void BroadcastTutorialPopupCanceled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTutorialProgressUpdated(int32 CurrentPhase);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupInputActionNames(const TArray<FName>& Names);

	UFUNCTION(BlueprintCallable)
	void SkipGuidedTutorial();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateInputDisplay(ECommonInputType CurrentInputType);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Screen Config")
	bool bLimitedDisplayDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Screen Config")
	float DisplayDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InputData")
	TArray<FName> InputAction_NameArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InputData")
	TArray<FName> GamepadInputAction_NameArray;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InputData", meta=(AllowPrivateAccess="TRUE"))
	FDataTableRowHandle DataTableRow;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortAthenaTutorialBaseInteraction> Interaction_TutorialStep;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortAthenaTutorialBaseInteraction> InteractionRegular_TutorialStep;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UUserWidget> MoveableHighlight;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UUserWidget> MoveableHighlight_Regular;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaTutorialScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher;

};

