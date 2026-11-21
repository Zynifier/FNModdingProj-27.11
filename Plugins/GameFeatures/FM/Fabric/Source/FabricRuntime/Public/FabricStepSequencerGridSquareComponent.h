// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Math/MathFwd.h"
#include "FabricInteractableInterface.h"
#include "FabricStepSequencerGridSquareComponent.generated.h"

class APlayerController;
class UFabricStepSequencerComponent;
class UStaticMeshComponent;

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent, DisplayName="Fabric Step Sequencer Grid Square"))
class FABRICRUNTIME_API UFabricStepSequencerGridSquareComponent : public UStaticMeshComponent, public IFabricInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetActiveTrack(int32 Track);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnContinuationControl_EndInteraction(APlayerController* Controller);

	UFUNCTION(BlueprintImplementableEvent)
	void OnContinuationControl_StartInteraction(APlayerController* Controller);

	UPROPERTY(EditAnywhere, Category="FabricStepSequencerGridSquareComponent")
	TSubclassOf<UStaticMeshComponent> GridSquareIconClass;

	UPROPERTY(EditAnywhere, Category="FabricStepSequencerGridSquareComponent")
	FVector IconRelativeLocation;

	UPROPERTY(EditAnywhere, Category="FabricStepSequencerGridSquareComponent")
	FVector IconRelativeScale;

	UPROPERTY(EditAnywhere, Category="FabricStepSequencerGridSquareComponent")
	float ContinuationControlInteractionDelay;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FabricStepSequencerGridSquareComponent", meta=(EditInline="true"))
	TObjectPtr<UFabricStepSequencerComponent> AssignedStepSequencer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricStepSequencerGridSquareComponent")
	int32 ActiveTrack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricStepSequencerGridSquareComponent")
	int32 AssignedStep;

	UPROPERTY(Transient)
	int32 PreviousFocusStepIndex;

private:
	UFUNCTION(BlueprintPure)
	bool CanDoInteractionLogicOnEndInteraction() const;

	UFUNCTION(BlueprintPure)
	bool CanDoInteractionLogicOnStartInteraction() const;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> IconComponent;

};

