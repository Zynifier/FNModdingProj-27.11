// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueInterface.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Math/MathFwd.h"
#include "StateDrivenActorTypes.generated.h"

class UMaterialInstance;
class UStaticMesh;

UENUM(BlueprintType)
enum class EStateDrivenStateID : uint8
{
	Invalid = 0,
	Success = 1,
	Failure = 2,
	State_A = 3,
	State_B = 4,
	State_C = 5,
	State_D = 6,
	State_E = 7,
	State_F = 8,
	State_G = 9,
	State_H = 10,
	State_I = 11,
	State_J = 12,
};

USTRUCT(BlueprintType)
struct FStateDrivenStateTransitions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenStateTransitions", meta=(Categories="StateDrivenActor.Events.Transition"))
	FGameplayTag TransitionTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenStateTransitions", meta=(BaseStruct="/Script/StateDrivenActorRuntime.StateDrivenEvent", ExcludeBaseStruct))
	TArray<FInstancedStruct> TransitionEvents;

};

USTRUCT(BlueprintType)
struct FStateDrivenState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="StateDrivenState")
	FString DevNotes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	bool bApplyMeshTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	FTransform StaticMeshTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	TArray<TSoftObjectPtr<UMaterialInstance>> MaterialInstances;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	FGameplayCueTag LoopingGameplayCueTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	float OverlapRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	FText InteractionStringOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	FText InteractionFailedStringOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenState")
	TArray<FStateDrivenStateTransitions> Transitions;

};

