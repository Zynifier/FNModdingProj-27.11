// Copyright Epic Games, Inc. All Rights Reserved.

#include "LevelSaveComponent.h"

void ULevelSaveBaseComponent::ConstructNewLevelRecord(AActor* Owner)
{
}

void ULevelSaveBaseComponent::LoadLevelRecord()
{
}

void ULevelSaveBaseComponent::OnFinishedRecordWrite(const FAsyncTaskResult& Result)
{
}

void ULevelSaveBaseComponent::OnFinishSpawning(const FAsyncTaskResult& Result)
{
}

void ULevelSaveBaseComponent::RegisterCreationToRollback(AActor* Actor)
{
}

bool ULevelSaveBaseComponent::RegisterDeletedActor(AActor* Actor)
{
	return false;
}

void ULevelSaveBaseComponent::RegisterDeletionToRollback(AActor* Actor)
{
}

void ULevelSaveBaseComponent::RegisterModificationToRollback(AActor* Actor)
{
}

bool ULevelSaveBaseComponent::RegisterNewActor(AActor* Actor)
{
	return false;
}

bool ULevelSaveBaseComponent::ResaveActor(AActor* Actor)
{
	return false;
}

void ULevelSaveBaseComponent::SaveOutLevelRecord()
{
}

void ULevelSaveBaseComponent::StartPeriodicSaveTimer()
{
}

void ULevelSaveBaseComponent::StopPeriodicSaveTimer()
{
}
