// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ContextualAnimSceneActorComponent.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "UObject/NoExportTypes.h"
#include "FortAthenaPlayContextualAnimStateTreeTask.generated.h"

class AActor;
class UAnimMontage;
class UContextualAnimSceneAsset;

UENUM(BlueprintType)
enum class EFortAthenaPlayContextualAnimExecutionMethod : uint8
{
	/** Start a new interaction */
	StartInteraction = 0,
	/** Join an existing interaction */
	JoinInteraction = 1,
	/** Transition a single actor in an interaction to a different section */
	TransitionAllActors = 2,
	/** Transition all the actors in an interaction to a different sections */
	TransitionSingleActor = 3,
};

USTRUCT(meta=(DisplayName="(Fortnite) Play Contextual Anim"))
struct FFortAthenaPlayContextualAnimStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

UCLASS()
class UFortAthenaPlayContextualAnimTaskInstanceData : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnMontageEnded(const UAnimMontage* EndedMontage, const bool bInterrupted);

	UFUNCTION()
	void OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<AActor> PrimaryActor;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<AActor> SecondaryActor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FName SecondaryRole;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<AActor> TertiaryActor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FName TertiaryRole;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<UContextualAnimSceneAsset> SceneAsset;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FName SectionName;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer PrimaryActorExternalTags;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer SecondaryActorExternalTags;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer TertiaryActorExternalTags;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaPlayContextualAnimExecutionMethod ExecutionMethod;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bWaitForNotifyEventToEnd;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="bWaitForNotifyEventToEnd"))
	FName NotifyEventNameToEnd;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(ClampMin="1", EditCondition="!bLoopForever"))
	int32 LoopsToRun;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bLoopForever;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(ClampMin="0.0"))
	float DelayBetweenLoops;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(ClampMin="0.0"))
	float RandomDeviationBetweenLoops;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TArray<FContextualAnimWarpTarget> WarpTargets;

};

