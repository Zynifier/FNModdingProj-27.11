// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/GameStateComponents/FortGameStateComponent_EventLevel.h"

void UFortGameStateComponent_EventLevel::CanGainRestedXp(bool& bResult) const
{
}

void UFortGameStateComponent_EventLevel::EndRestXpTimer()
{
}

FGameplayTag UFortGameStateComponent_EventLevel::GetActiveCameraTag() const
{
	return FGameplayTag();
}

AFortEventLevelNavigationActor* UFortGameStateComponent_EventLevel::GetLastNavObject() const
{
	return nullptr;
}

FText UFortGameStateComponent_EventLevel::GetRandomNavIndicatorTextFromList(const FGameplayTag& ListNameTag)
{
	return FText();
}

AFortPlayerController* UFortGameStateComponent_EventLevel::GetRoomOwner() const
{
	return nullptr;
}

void UFortGameStateComponent_EventLevel::GoToCamera(FGameplayTag CameraToViewFrom)
{
}

void UFortGameStateComponent_EventLevel::HandleNavigationActorUnhover(AFortEventLevelNavigationActor* InActor)
{
}

void UFortGameStateComponent_EventLevel::HandleOnCameraBlendComplete()
{
}

void UFortGameStateComponent_EventLevel::HandleOnCameraCut(UCameraComponent* CameraComponent)
{
}

void UFortGameStateComponent_EventLevel::HandlePreOpenPackageComplete() const
{
}

void UFortGameStateComponent_EventLevel::HoverActorUnderCursor()
{
}

void UFortGameStateComponent_EventLevel::LinkNavActorToCamera(AFortEventLevelNavigationActor* InActor, FGameplayTag CameraTag)
{
}

void UFortGameStateComponent_EventLevel::NotifyRestedXpGenAmount(int32 RestedXp)
{
}

bool UFortGameStateComponent_EventLevel::RegisterCamera(AFortEventLevelCamera* InCamera)
{
	return false;
}

void UFortGameStateComponent_EventLevel::RegisterHiddenActor(AActor* InActor, FGameplayTag EventGraphNode)
{
}

bool UFortGameStateComponent_EventLevel::RegisterNavigationActor(AFortEventLevelNavigationActor* InActor)
{
	return false;
}

void UFortGameStateComponent_EventLevel::SetActiveCamera(FGameplayTag NewActiveCamera, bool bUseTransition)
{
}

void UFortGameStateComponent_EventLevel::StartRestedXpTimer()
{
}

void UFortGameStateComponent_EventLevel::TryToClaimRewardGraphNode(FGameplayTag NodeTag) const
{
}
