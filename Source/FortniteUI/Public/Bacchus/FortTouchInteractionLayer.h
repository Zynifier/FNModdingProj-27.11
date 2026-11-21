// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "CommonUserWidget.h"
#include "FortTouchInteractionLayer.generated.h"

class AActor;
class AFortPlayerController;
class UCanvasPanel;
class UFortActorComponent_MultiInteract;
class UFortControllerComponent_Interaction;
class UFortInteractContextInfo;
class UFortTouchInteractionButton;

USTRUCT()
struct FButtonInteractionPair
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> TrackedInteraction;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortTouchInteractionButton> TrackedButton;

};

UCLASS()
class UFortTouchInteractionLayer : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void AddInteraction(AActor* In);

	UFUNCTION()
	void RefreshVisuals(const int32 InteractingActorCount, const float InteractingMultiplier, const float InteractDuration);

	UFUNCTION(BlueprintCallable)
	void RemoveInteraction(AActor* In);

	UFUNCTION()
	void UpdateButtonFocusForInteraction(UFortInteractContextInfo* NewInteraction);

	UFUNCTION(BlueprintCallable)
	void UpdateButtonTimer(AActor* In, float TotalDuration, float Remaining);

	UFUNCTION(BlueprintCallable)
	void UpdateInteractingButtonTimer(const float TotalDuration, const float Remaining, const float InteractingMultiplier);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortTouchInteractionLayer", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UFortTouchInteractionButton> WidgetClass;

	UPROPERTY(Transient)
	FUserWidgetPool WidgetPool;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCanvasPanel> ContentPanel;

	UPROPERTY(Transient)
	TArray<FButtonInteractionPair> InteractableButtonMap;

	UPROPERTY(Transient)
	TObjectPtr<AActor> FocusedInteraction;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> OwningPC;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Interaction> InteractionComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActorComponent_MultiInteract> MultiInteractComponent;

};

