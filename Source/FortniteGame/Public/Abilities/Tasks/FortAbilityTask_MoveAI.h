// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AITypes.h"
#include "Actions/PawnAction_Move.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "AI/FortPathFollowingComponent.h"
#include "AI/Tasks/FortAITask_Move.h"
#include "FortAbilityTask_MoveAI.generated.h"

class AActor;
class AFortPawn;
class UFortAbilityTask_MoveAI;
class UGameplayAbility;
class UNavigationQueryFilter;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMoveAIDelegate);

UCLASS(MinimalAPI)
class UFortAbilityTask_MoveAI : public UFortAITask_Move
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(AdvancedDisplay="bStopAtEnd,bFinishOnPlayerCollision,bProjectGoalLocationOnNavMesh,bUseContinuousGoalTracking,RequireNavigableEndLocation", BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", DisplayName="MoveAI", HidePin="OwningAbility", CPP_Default_PathObstacleAction="Melee", CPP_Default_bStopAtEnd="true", CPP_Default_AcceptPartialPath="Default", CPP_Default_bFinishOnPlayerCollision="false", CPP_Default_bProjectGoalLocationOnNavMesh="true", CPP_Default_AcceptableRadius="-1.000000", CPP_Default_PushBumpedPawnClass="None", CPP_Default_FilterClass="None", CPP_Default_NavFilterTag="()"))
	FORTNITEGAME_API static UFortAbilityTask_MoveAI* CreateMoveAITask(UGameplayAbility* OwningAbility, FName TaskInstanceName, AActor* MoveActor, FVector MoveLocation, EPawnActionMoveMode::Type MoveMode, EPathObstacleAction::Type PathObstacleAction, bool bStopAtEnd, EAIOptionFlag::Type AcceptPartialPath, bool bFinishOnPlayerCollision, bool bProjectGoalLocationOnNavMesh, float AcceptableRadius, TSubclassOf<AFortPawn> PushBumpedPawnClass, TSubclassOf<UNavigationQueryFilter> FilterClass, FGameplayTag NavFilterTag, bool bUseContinuousGoalTracking = false, EAIOptionFlag::Type RequireNavigableEndLocation = EAIOptionFlag::Default);

	UPROPERTY(BlueprintAssignable)
	FMoveAIDelegate OnComplete;

	UPROPERTY(BlueprintAssignable)
	FMoveAIDelegate OnInterrupted;

	UPROPERTY(BlueprintAssignable)
	FMoveAIDelegate OnCancelled;

};

