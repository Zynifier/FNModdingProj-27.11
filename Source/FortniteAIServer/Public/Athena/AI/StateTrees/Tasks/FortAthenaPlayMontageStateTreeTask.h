// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "FortAthenaPlayMontageStateTreeTask.generated.h"

class AActor;
class UAnimMontage;

UCLASS(BlueprintType, Blueprintable, meta=(DisplayName="(Fortnite) Play Anim Montage"))
class UFortAthenaPlayMontageStateTreeTask : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()

public:
	UFortAthenaPlayMontageStateTreeTask(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void HandleMontageEnded(const UAnimMontage* EndedMontage, const bool bInterrupted);

	UFUNCTION()
	void HandleNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bWaitForNotifyEventToEnd;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="bWaitForNotifyEventToEnd"))
	FName NotifyEventNameToEnd;

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
	bool bStopAnimMontageOnExit;

};

