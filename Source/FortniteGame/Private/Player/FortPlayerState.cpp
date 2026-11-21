// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortPlayerState.h"
#include "Net/UnrealNetwork.h"

bool AFortPlayerState::AreUniqueIDsIdentical(const FUniqueNetIdRepl& A, const FUniqueNetIdRepl& B)
{
	return false;
}

void AFortPlayerState::ChangeActiveVariantForCosmeticItem(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn)
{
}

AFortPlayerPawn* AFortPlayerState::GetCurrentPawn() const
{
	return nullptr;
}

const UFortHeroType* AFortPlayerState::GetHeroType() const
{
	return nullptr;
}

FString AFortPlayerState::GetPlatform() const
{
	return FString();
}

FUniqueNetIdRepl AFortPlayerState::GetPlatformUniqueNetId() const
{
	return FUniqueNetIdRepl();
}

FName AFortPlayerState::GetPlayerOSSName() const
{
	return FName();
}

AFortPlayerPawn* AFortPlayerState::GetPlayerPawnOrVehicleDriver() const
{
	return nullptr;
}

FUniqueNetIdRepl AFortPlayerState::GetPlayerUniqueNetID() const
{
	return FUniqueNetIdRepl();
}

FUniqueNetIdRepl AFortPlayerState::GetUniqueID() const
{
	return FUniqueNetIdRepl();
}

bool AFortPlayerState::HasLocalPlayerController() const
{
	return false;
}

bool AFortPlayerState::HasStartedPlaying() const
{
	return false;
}

bool AFortPlayerState::IsSimulatingDamage() const
{
	return false;
}

void AFortPlayerState::OnInstigatorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void AFortPlayerState::OnRep_AccessoryColorSwatches()
{
}

void AFortPlayerState::OnRep_BannerInfo()
{
}

void AFortPlayerState::OnRep_bHasStartedPlaying()
{
}

void AFortPlayerState::OnRep_bIsSimulatingDamage()
{
}

void AFortPlayerState::OnRep_CharacterBodyType()
{
}

void AFortPlayerState::OnRep_CharacterColorSwatches()
{
}

void AFortPlayerState::OnRep_CharacterData()
{
}

void AFortPlayerState::OnRep_CharacterGender()
{
}

void AFortPlayerState::OnRep_CurrentCharXP()
{
}

void AFortPlayerState::OnRep_HeroID()
{
}

void AFortPlayerState::OnRep_HeroType()
{
}

void AFortPlayerState::OnRep_HomeActor(AActor* OldHomeActor)
{
}

void AFortPlayerState::OnRep_InGhostMode()
{
}

void AFortPlayerState::OnRep_PartyOwner()
{
}

void AFortPlayerState::OnRep_Platform()
{
}

void AFortPlayerState::OnRep_PlatformUniqueNetId()
{
}

void AFortPlayerState::OnRep_PlayerTeam()
{
}

void AFortPlayerState::OnRep_PlayerTeamPrivate()
{
}

void AFortPlayerState::OnRep_ScoreStatChanged()
{
}

void AFortPlayerState::OnRep_SessionOwner()
{
}

void AFortPlayerState::ServerChangeActiveVariantForCosmeticItem_Implementation(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn)
{
}
bool AFortPlayerState::ServerChangeActiveVariantForCosmeticItem_Validate(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn)
{
	return true;
}

void AFortPlayerState::SetIsSimulatingDamage(const bool bSimulateDamage)
{
}

void AFortPlayerState::UpdateScoreStatChanged()
{
}

void AFortPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerState, bIsWorldDataOwner);
	DOREPLIFETIME(AFortPlayerState, bIsGameSessionOwner);
	DOREPLIFETIME(AFortPlayerState, bIsGameSessionAdmin);
	DOREPLIFETIME(AFortPlayerState, bIsReadyToContinue);
	DOREPLIFETIME(AFortPlayerState, bHasFinishedLoading);
	DOREPLIFETIME(AFortPlayerState, bHasStartedPlaying);
	DOREPLIFETIME(AFortPlayerState, bRepFlag1);
	DOREPLIFETIME(AFortPlayerState, PlayerRole);
	DOREPLIFETIME(AFortPlayerState, WorldPlayerId);
	DOREPLIFETIME(AFortPlayerState, PartyOwnerUniqueId);
	DOREPLIFETIME(AFortPlayerState, HeroId);
	DOREPLIFETIME(AFortPlayerState, HeroType);
	DOREPLIFETIME(AFortPlayerState, CurrentCharXP);
	DOREPLIFETIME(AFortPlayerState, MyBackpackPickup);
	DOREPLIFETIME(AFortPlayerState, InitialExperienceLevel);
	DOREPLIFETIME(AFortPlayerState, InitialExperienceAmount);
	DOREPLIFETIME(AFortPlayerState, ExperienceDeltas);
	DOREPLIFETIME(AFortPlayerState, Platform);
	DOREPLIFETIME(AFortPlayerState, Banner);
	DOREPLIFETIME(AFortPlayerState, bIsSimulatingDamage);
	DOREPLIFETIME(AFortPlayerState, EOSProductUserId);
	DOREPLIFETIME(AFortPlayerState, CharacterGender);
	DOREPLIFETIME(AFortPlayerState, CharacterBodyType);
	DOREPLIFETIME(AFortPlayerState, CharacterData);
	DOREPLIFETIME(AFortPlayerState, CharacterColorSwatches);
	DOREPLIFETIME(AFortPlayerState, CharacterPartColorSwatches);
	DOREPLIFETIME(AFortPlayerState, PlayerTeam);
	DOREPLIFETIME(AFortPlayerState, PlayerTeamPrivate);
	DOREPLIFETIME(AFortPlayerState, ReplicatedStats_Campaign);
	DOREPLIFETIME(AFortPlayerState, ReplicatedStats_Zone);
	DOREPLIFETIME(AFortPlayerState, bAreZoneStatsFinalized);
	DOREPLIFETIME(AFortPlayerState, ReadyCheckState);
	DOREPLIFETIME(AFortPlayerState, HomeActor);
	DOREPLIFETIME(AFortPlayerState, PlatformUniqueNetId);
	DOREPLIFETIME(AFortPlayerState, bInGhostMode);
}

UAbilitySystemComponent* AFortPlayerState::GetAbilitySystemComponent() const
{
	return nullptr;
}
