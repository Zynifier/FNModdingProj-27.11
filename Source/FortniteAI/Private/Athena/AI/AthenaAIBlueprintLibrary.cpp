// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/AthenaAIBlueprintLibrary.h"

bool UAthenaAIBlueprintLibrary::AIPawnFromGAHasLuringPickupAsGoal(const FGameplayAbilityActorInfo& ActorInfo, const FGameplayTag GameplayTag, const float MaxLifeTime, const EFortPickupSpawnSource RequiredPickupSpawnSource)
{
	return false;
}

APawn* UAthenaAIBlueprintLibrary::AthenaSpawnAIFromClass(UObject* WorldContextObject, TSubclassOf<APawn> PawnClass, UBehaviorTree* BehaviorTree, FVector Location, FRotator Rotation, bool bNoCollisionFail, AActor* Owner)
{
	return nullptr;
}

UAthenaAIPopulationTracker* UAthenaAIBlueprintLibrary::GetAIPopulationTracker(UObject* WorldContextObject)
{
	return nullptr;
}

UAthenaAIServiceCreativePlayerBots* UAthenaAIBlueprintLibrary::GetAIServiceCreativePlayerBots(const UObject* WorldContextObject)
{
	return nullptr;
}

UAthenaAIServiceLoot* UAthenaAIBlueprintLibrary::GetAIServiceLoot(UObject* WorldContextObject)
{
	return nullptr;
}

UAthenaAIServicePlayerBots* UAthenaAIBlueprintLibrary::GetAIServicePlayerBots(UObject* WorldContextObject)
{
	return nullptr;
}

bool UAthenaAIBlueprintLibrary::IsItemDefinitionSupported(UObject* WorldContextObject, const UFortItemDefinition* FortItemDef)
{
	return false;
}

bool UAthenaAIBlueprintLibrary::IsWeaponSupported(UObject* WorldContextObject, AFortWeapon* FortWeapon)
{
	return false;
}

void UAthenaAIBlueprintLibrary::JoinTeam(UObject* WorldContextObject, const AController* SourceTeamController, AController* DestinationTeamController)
{
}

void UAthenaAIBlueprintLibrary::KillBots(UObject* WorldContextObject, const bool bKillPlayers, const bool bKillNoneParticipants, const uint8 TeamIndex, AActor* BotOwner)
{
}

void UAthenaAIBlueprintLibrary::MakeBotGroupsTakeEachOtherAsTargets(const TArray<AActor*>& GroupA, const TArray<AActor*>& GroupB, EPerceptionState PerceptionState, float ForgetTime, float ForgetDistance)
{
}
