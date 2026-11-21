// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Styling/SlateTypes.h"
#include "Types/SlateEnums.h"
#include "FabricAnimatableButtonInterface.h"
#include "FabricInteractableInterface.h"
#include "FabricButtonBase.generated.h"

class APlayerController;
class UFabricInteractableViewModel;
class UTimelineComponent;

UCLASS(Transient, BlueprintType, Blueprintable, meta=(Category="Harmonix"))
class FABRICRUNTIME_API AFabricButtonBase : public AActor, public IFabricInteractable, public IFabricAnimatableButtonInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FToggleStateChanged, APlayerController*, InteractingController, bool, IsToggle);

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="FabricButton|Feedback")
	UTimelineComponent* GetCloseTimeline();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="FabricButton|Feedback")
	UTimelineComponent* GetOpenTimeline();

	UFUNCTION(BlueprintNativeEvent, Category="FabricButton|Logic")
	void HandleButtonClicked();

	UFUNCTION(BlueprintNativeEvent, Category="FabricButton|Logic")
	void HandleButtonDoubleClicked();

	UFUNCTION(BlueprintNativeEvent, Category="FabricButton|Logic")
	void HandleButtonHovered();

	UFUNCTION(BlueprintNativeEvent, Category="FabricButton|Logic")
	void HandleButtonPressed();

	UFUNCTION(BlueprintNativeEvent, Category="FabricButton|Logic")
	void HandleButtonReleased();

	UFUNCTION(BlueprintNativeEvent, Category="FabricButton|Logic")
	void HandleButtonUnhovered();

	UFUNCTION(BlueprintPure, Category="FabricButton|Logic")
	bool IsEnabled();

	UFUNCTION(BlueprintPure, Category="FabricButton|Logic")
	bool IsHovered();

	UFUNCTION(BlueprintPure, Category="FabricButton|Logic")
	bool IsPressed();

	UFUNCTION(BlueprintPure, Category="FabricButton|Logic")
	bool IsToggledOn();

	UFUNCTION(BlueprintNativeEvent)
	void OnButtonClicked();

	UFUNCTION(BlueprintNativeEvent)
	void OnButtonDoubleClicked();

	UFUNCTION(BlueprintNativeEvent)
	void OnButtonPressed();

	UFUNCTION(BlueprintNativeEvent)
	void OnButtonReleased();

	UFUNCTION(BlueprintNativeEvent)
	void OnDisabled();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnEnabled();

	UFUNCTION(BlueprintNativeEvent)
	void OnHovered();

	UFUNCTION(BlueprintNativeEvent)
	void OnToggleStateChanged(bool bIsToggled);

	UFUNCTION(BlueprintNativeEvent)
	void OnUnhovered();

	UFUNCTION(BlueprintCallable, Category="FabricButton|Logic")
	void SetEnabled(bool bNewEnabled);

	UFUNCTION(BlueprintCallable, Category="FabricButton|Logic")
	void SetToggleState(bool bNewToggleState, bool bBroadcast, bool bForce);

	UFUNCTION(BlueprintCallable)
	void SetWidgetViewModel(UFabricInteractableViewModel* ViewModel);

	UFUNCTION(BlueprintCallable, Category="FabricButton|Logic")
	void SwapToggle();

	UPROPERTY(EditDefaultsOnly, BlueprintAssignable, Category="FabricButton|Feedback")
	FToggleStateChanged ToggleStateChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricButtonConfig")
	double OpenTimeSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricButtonConfig")
	double CloseTimeSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricButtonConfig")
	bool bHasToggle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricButtonConfig")
	TEnumAsByte<EButtonPressMethod::Type> ClickMethod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Default")
	TObjectPtr<APlayerController> InteractingController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FabricButtonBase")
	FString ButtonId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricButtonBase")
	FText ButtonLabel;

private:
	UPROPERTY(EditDefaultsOnly, Category="FabricButtonConfig")
	bool bEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	bool bHovered;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	bool bPressed;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	ECheckBoxState ToggleState;

	UPROPERTY(Transient)
	TObjectPtr<UFabricInteractableViewModel> WidgetViewModel;

};

