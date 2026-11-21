// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_MoveAI.h"

UFortAbilityTask_MoveAI* UFortAbilityTask_MoveAI::CreateMoveAITask(UGameplayAbility* OwningAbility, FName TaskInstanceName, AActor* MoveActor, FVector MoveLocation, EPawnActionMoveMode::Type MoveMode, EPathObstacleAction::Type PathObstacleAction, bool bStopAtEnd, EAIOptionFlag::Type AcceptPartialPath, bool bFinishOnPlayerCollision, bool bProjectGoalLocationOnNavMesh, float AcceptableRadius, TSubclassOf<AFortPawn> PushBumpedPawnClass, TSubclassOf<UNavigationQueryFilter> FilterClass, FGameplayTag NavFilterTag, bool bUseContinuousGoalTracking, EAIOptionFlag::Type RequireNavigableEndLocation)
{
	return nullptr;
}
