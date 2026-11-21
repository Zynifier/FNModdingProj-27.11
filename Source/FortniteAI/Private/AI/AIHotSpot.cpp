// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/AIHotSpot.h"

void AAIHotSpot::AssignFromWaitingList()
{
}

int32 AAIHotSpot::AssignGroupToHotspot(TArray<AAIController*> GroupOfAI)
{
	return int32();
}

bool AAIHotSpot::AssignToHotspot(AAIController* AI)
{
	return false;
}

bool AAIHotSpot::AssignToSlotByIndex(AAIController* AI, int32 Index)
{
	return false;
}

bool AAIHotSpot::CanUseSlotByIndex(const AAIController* AI, int32 Index) const
{
	return false;
}

int32 AAIHotSpot::FindBestSlotIndex(AAIController* AI) const
{
	return int32();
}

TArray<int32> AAIHotSpot::FindBestSlotIndices(TArray<AAIController*> AI) const
{
	return TArray<int32>();
}

TArray<AAIController*> AAIHotSpot::GetAssignedAI(EAIHotSpotAssignmentFilter Filter) const
{
	return TArray<AAIController*>();
}

int32 AAIHotSpot::GetAssignedAICount(EAIHotSpotAssignmentFilter Filter) const
{
	return int32();
}

UAIHotSpotSlot* AAIHotSpot::GetSlotByIndex(int32 Index) const
{
	return nullptr;
}

UAIHotSpotSlot* AAIHotSpot::GetSlotByOwner(const AAIController* AIOwner) const
{
	return nullptr;
}

int32 AAIHotSpot::GetSlotCount(EAIHotSpotSlotFilter Filter) const
{
	return int32();
}

int32 AAIHotSpot::GetSlotIndexByOwner(const AAIController* AIOwner) const
{
	return int32();
}

FVector AAIHotSpot::GetSlotLocationByIndex(int32 Index) const
{
	return FVector();
}

AAIController* AAIHotSpot::GetSlotOwnerByIndex(int32 Index) const
{
	return nullptr;
}

FRotator AAIHotSpot::GetSlotRotationByIndex(int32 Index) const
{
	return FRotator();
}

EAIHotSpotSlot AAIHotSpot::GetSlotStateByIndex(int32 Index) const
{
	return EAIHotSpotSlot();
}

EAIHotSpotSlot AAIHotSpot::GetSlotStateByOwner(const AAIController* AIOwner) const
{
	return EAIHotSpotSlot();
}

int32 AAIHotSpot::GetSlotUserIdByIndex(int32 Index) const
{
	return int32();
}

bool AAIHotSpot::HasAssignedAI(const AAIController* AI, EAIHotSpotAssignmentFilter Filter) const
{
	return false;
}

bool AAIHotSpot::HasEnabledSlots() const
{
	return false;
}

bool AAIHotSpot::IsAIAllowed_Implementation(const AAIController* AI) const
{
	return false;
}

bool AAIHotSpot::IsEnabled() const
{
	return false;
}

bool AAIHotSpot::IsSlotlessAssignmentAllowed() const
{
	return false;
}

bool AAIHotSpot::OccupySlotByIndex(int32 Index)
{
	return false;
}

bool AAIHotSpot::OnAssignedClaimedBehavior_Implementation(AAIController* AI, int32 Index, int32 UserId, bool bWasOnWaitingList)
{
	return false;
}

bool AAIHotSpot::OnAssignedOccupiedBehavior_Implementation(AAIController* AI, int32 Index, int32 UserId)
{
	return false;
}

bool AAIHotSpot::OnAssignedSlotlessBehavior_Implementation(AAIController* AI)
{
	return false;
}

void AAIHotSpot::OnHotSpotDisabled_Implementation()
{
}

void AAIHotSpot::OnHotSpotEnabled_Implementation()
{
}

void AAIHotSpot::OnMoveToSlotFinished_Implementation(AAIController* AI, int32 Index, int32 UserId, bool bResult)
{
}

void AAIHotSpot::OnRemovedBehavior_Implementation(AAIController* AI, int32 Index, int32 UserId, EAIHotSpotSlot PrevState, bool bWasOnWaitingList)
{
}

void AAIHotSpot::OnRemovedSlotlessBehavior_Implementation(AAIController* AI, bool bIsClamingSlot)
{
}

void AAIHotSpot::OnSlotBlocked_Implementation(AAIController* AI, int32 Index, int32 UserId)
{
}

void AAIHotSpot::OnSlotClaimed_Implementation(AAIController* AI, int32 Index, int32 UserId)
{
}

void AAIHotSpot::OnSlotDisabled_Implementation(int32 Index, int32 UserId)
{
}

void AAIHotSpot::OnSlotEnabled_Implementation(int32 Index, int32 UserId)
{
}

void AAIHotSpot::OnSlotFreed_Implementation(AAIController* AI, int32 Index, int32 UserId)
{
}

void AAIHotSpot::OnSlotOccupied_Implementation(AAIController* AI, int32 Index, int32 UserId)
{
}

bool AAIHotSpot::RemoveFromHotspot(AAIController* AI, bool bAssignFromWaitingList)
{
	return false;
}

int32 AAIHotSpot::RemoveGroupFromHotspot(TArray<AAIController*> GroupOfAI)
{
	return int32();
}

void AAIHotSpot::SetEnabled(bool bEnabled)
{
}
