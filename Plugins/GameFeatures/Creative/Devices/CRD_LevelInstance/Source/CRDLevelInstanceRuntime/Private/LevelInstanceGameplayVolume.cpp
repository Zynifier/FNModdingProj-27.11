// Copyright Epic Games, Inc. All Rights Reserved.

#include "LevelInstanceGameplayVolume.h"
#include "Net/UnrealNetwork.h"

void ALevelInstanceGameplayVolume::CheckForOverlappingVolumes()
{
}

AFortLevelInstanceSaveActor* ALevelInstanceGameplayVolume::CreateLevelInstanceSaveActor()
{
	return nullptr;
}

FString ALevelInstanceGameplayVolume::GetLevelInstanceName() const
{
	return FString();
}

void ALevelInstanceGameplayVolume::HandleActorHealthChanged(AActor* Actor, float NewHealth)
{
}

void ALevelInstanceGameplayVolume::InstantiateFromLevelInstanceSaveActor()
{
}

bool ALevelInstanceGameplayVolume::IsDisabled() const
{
	return false;
}

bool ALevelInstanceGameplayVolume::IsInEditMode() const
{
	return false;
}

bool ALevelInstanceGameplayVolume::IsPreviewActor() const
{
	return false;
}

void ALevelInstanceGameplayVolume::LevelInstanceBeingDestroyed()
{
}

void ALevelInstanceGameplayVolume::LevelInstanceContentChanged(const AActor* InstigatorActor)
{
}

void ALevelInstanceGameplayVolume::LevelInstanceContentCollectionChanged(const AActor* InstigatorActor, TSoftObjectPtr<UFortCreativeActorCollection> ContentCollection)
{
}

void ALevelInstanceGameplayVolume::LevelInstanceNameChanged(const FString& Name)
{
}

void ALevelInstanceGameplayVolume::LevelInstanceSizeChanged(const AActor* InstigatorActor)
{
}

void ALevelInstanceGameplayVolume::OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MiniGameState)
{
}

void ALevelInstanceGameplayVolume::OnRep_EditMode()
{
}

void ALevelInstanceGameplayVolume::OnRep_InstanceLoaded()
{
}

void ALevelInstanceGameplayVolume::OnRep_IsDisabled()
{
}

void ALevelInstanceGameplayVolume::RemoveActorWhenDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void ALevelInstanceGameplayVolume::RemoveActorWhenEndPlay(AActor* Actor, const EEndPlayReason::Type EndPlayReason)
{
}

void ALevelInstanceGameplayVolume::SetEditMode(bool bInEditMode)
{
}

void ALevelInstanceGameplayVolume::SetLevelInstanceActorGuid(FGuid InLevelInstanceActorGuid)
{
}

void ALevelInstanceGameplayVolume::SetLevelInstanceContentCollection(TSoftObjectPtr<UFortCreativeActorCollection> ContentCollection)
{
}

void ALevelInstanceGameplayVolume::SetLevelInstanceName(const FString& InName)
{
}

void ALevelInstanceGameplayVolume::SetReadyForInstantiation(bool bReady)
{
}

void ALevelInstanceGameplayVolume::SetWantsLevelLoaded(bool bInWantsLevelLoaded)
{
}

void ALevelInstanceGameplayVolume::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALevelInstanceGameplayVolume, bEditMode);
	DOREPLIFETIME(ALevelInstanceGameplayVolume, bDisabled);
	DOREPLIFETIME(ALevelInstanceGameplayVolume, LoadingState);
	DOREPLIFETIME(ALevelInstanceGameplayVolume, LevelInstanceName);
	DOREPLIFETIME(ALevelInstanceGameplayVolume, bInstanceLoaded);
	DOREPLIFETIME(ALevelInstanceGameplayVolume, bWantsLevelLoaded);
}
