// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIPatrolPathComponent.h"

bool UAIPatrolPathComponent::CanNextPointBeReached() const
{
	return false;
}

void UAIPatrolPathComponent::GeneratePathPoints(const EFortCreativePatrolPathGroup PatrolPathGroup, const bool bGenerationCausedByDuplication)
{
}

TArray<UAIPatrolPathComponent*> UAIPatrolPathComponent::GetLinkedPatrolPoints() const
{
	return TArray<UAIPatrolPathComponent*>();
}

bool UAIPatrolPathComponent::GetNextAvailablePatrolPathIndex(int32& NextAvailableIndex) const
{
	return false;
}

int32 UAIPatrolPathComponent::GetPatrolPathIndex() const
{
	return int32();
}

UAIPatrolPathComponent* UAIPatrolPathComponent::GetPatrolPathPoint(const int32 InPatrolPathIndex, const int32 InPatrolPathPointIndex) const
{
	return nullptr;
}

int32 UAIPatrolPathComponent::GetPatrolPathPointIndex() const
{
	return int32();
}

bool UAIPatrolPathComponent::HasValidPatrolPath() const
{
	return false;
}

void UAIPatrolPathComponent::NotifyEditorUserOptionChanged(const TArray<FString>& UserOptions)
{
}

void UAIPatrolPathComponent::OnAnyPropertyChanged()
{
}

#if WITH_EDITOR
void UAIPatrolPathComponent::OnEditorOwnerDestroyed(AActor* InActor)
{
}
#endif

#if WITH_EDITOR
void UAIPatrolPathComponent::OnOwnerDuplicated(bool bDuplicatedForPIE)
{
}
#endif

void UAIPatrolPathComponent::PatrolPathStarted(AAIController* Instigator)
{
}

void UAIPatrolPathComponent::PatrolPathStopped(AAIController* Instigator)
{
}

void UAIPatrolPathComponent::PatrolPointFailedToReach(AFortAthenaPatrolPoint* PathPoint, AAIController* Instigator)
{
}

void UAIPatrolPathComponent::PatrolPointReached(AFortAthenaPatrolPoint* PathPoint, AAIController* Instigator)
{
}

void UAIPatrolPathComponent::PostFinishSpawningActor()
{
}

bool UAIPatrolPathComponent::RemovePoint()
{
	return false;
}

void UAIPatrolPathComponent::RenderToNextAndPreviousPoint()
{
}

void UAIPatrolPathComponent::RenderToNextPoint()
{
}

void UAIPatrolPathComponent::RequestRenderPath()
{
}

void UAIPatrolPathComponent::SetPatrollingMode(const EPatrollingMode NewMode)
{
}

void UAIPatrolPathComponent::SetPatrolPathEnabled(const bool bIsEnabled)
{
}

void UAIPatrolPathComponent::SetPatrolPathGroup(const EFortCreativePatrolPathGroup PatrolPathGroup)
{
}

void UAIPatrolPathComponent::SetRenderPath(const bool bRenderPath)
{
}

void UAIPatrolPathComponent::UpdateEditorComponent()
{
}
