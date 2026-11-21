// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortAthenaTutorialBase.generated.h"

class AActor;

UENUM()
enum class EFortAthenaTutorial_StandaloneStep : uint8
{
	None = 0,
	HealingInterrupted = 1,
	Count = 2,
};

UCLASS()
class AFortAthenaTutorialBase : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsExecuting() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	FGameplayTagContainer DefaultHUDElementTags;

protected:
	UFUNCTION(Client, Reliable, Category="Tutorial")
	void ExecuteTutorialStep_Client(int32 StepIndex);

	UFUNCTION(Server, Reliable, Category="Tutorial")
	void OnClientStepCompleted_Server(int32 StepIndex);

	UFUNCTION(Client, Reliable, Category="Tutorial")
	void OnStartTutorial_Client();

	UFUNCTION(Client, Reliable, Category="Tutorial")
	void OnStopTutorial_Client();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, BlueprintAuthorityOnly)
	void SetEasyInteractIconActor(AActor* TrackedActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Movement", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<AActor> CameraStartPositionActor;

private:
	UFUNCTION()
	void OnRep_TrackedActor();

	UPROPERTY(Replicated)
	bool bExecuting;

	UPROPERTY(Replicated)
	int32 CurrentStepIndex;

	UPROPERTY(ReplicatedUsing=OnRep_TrackedActor)
	TObjectPtr<AActor> CurrentTrackedActor;

};

