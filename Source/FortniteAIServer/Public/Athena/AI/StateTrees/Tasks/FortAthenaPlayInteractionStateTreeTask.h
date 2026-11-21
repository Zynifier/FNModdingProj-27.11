// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "FortAthenaPlayInteractionStateTreeTask.generated.h"

class AActor;
class UAnimMontage;

USTRUCT()
struct FFortAthenaPlayInteractionStateTreeTaskActorInfo
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, meta=(DisplayName="(Fortnite) Play Interaction"))
class UFortAthenaPlayInteractionStateTreeTask : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()

public:
	UFortAthenaPlayInteractionStateTreeTask(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void OnMontageEnded(const UAnimMontage* EndedMontage, const bool bInterrupted);

	UFUNCTION()
	void OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> InteractorActor;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> InteractableActor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<UAnimMontage> InteractorMontage;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<UAnimMontage> InteractableMontage;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bWaitForNotifyEventToEnd;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="bWaitForNotifyEventToEnd"))
	FName NotifyEventNameToEnd;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bAddMotionWarpingTargets;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bDisableCollisionBetweenActors;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bSetMovementModeToFlying;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(ClampMin="1", EditCondition="!bLoopForever"))
	int32 LoopsToRun;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bLoopForever;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(ClampMin="0.0"))
	float DelayBetweenLoops;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(ClampMin="0.0"))
	float RandomDeviationBetweenLoops;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bStopInteractorAnimMontageOnExit;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bStopInteractableAnimMontageOnExit;

};

