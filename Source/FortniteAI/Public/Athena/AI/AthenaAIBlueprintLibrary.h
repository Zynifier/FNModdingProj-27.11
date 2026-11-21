// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "AthenaAIBlueprintLibrary.generated.h"

class AActor;
class AController;
class AFortWeapon;
class APawn;
class UAthenaAIPopulationTracker;
class UAthenaAIServiceCreativePlayerBots;
class UAthenaAIServiceLoot;
class UAthenaAIServicePlayerBots;
class UBehaviorTree;
class UFortItemDefinition;
class UObject;
enum class EFortPickupSpawnSource : uint8;
enum class EPerceptionState : uint8;

UCLASS(MinimalAPI)
class UAthenaAIBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI")
	static bool AIPawnFromGAHasLuringPickupAsGoal(const FGameplayAbilityActorInfo& ActorInfo, const FGameplayTag GameplayTag, const float MaxLifeTime, const EFortPickupSpawnSource RequiredPickupSpawnSource);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(AdvancedDisplay="Owner", UnsafeDuringActorConstruction="true", WorldContext="WorldContextObject", CPP_Default_Rotation))
	static APawn* AthenaSpawnAIFromClass(UObject* WorldContextObject, TSubclassOf<APawn> PawnClass, UBehaviorTree* BehaviorTree, FVector Location, FRotator Rotation, bool bNoCollisionFail = false, AActor* Owner = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI", meta=(WorldContext="WorldContextObject"))
	static UAthenaAIPopulationTracker* GetAIPopulationTracker(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI", meta=(WorldContext="WorldContextObject"))
	static UAthenaAIServiceCreativePlayerBots* GetAIServiceCreativePlayerBots(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI", meta=(WorldContext="WorldContextObject"))
	static UAthenaAIServiceLoot* GetAIServiceLoot(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI", meta=(WorldContext="WorldContextObject"))
	static UAthenaAIServicePlayerBots* GetAIServicePlayerBots(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(WorldContext="WorldContextObject"))
	static bool IsItemDefinitionSupported(UObject* WorldContextObject, const UFortItemDefinition* FortItemDef);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI", meta=(WorldContext="WorldContextObject"))
	static bool IsWeaponSupported(UObject* WorldContextObject, AFortWeapon* FortWeapon);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI", meta=(WorldContext="WorldContextObject"))
	static void JoinTeam(UObject* WorldContextObject, const AController* SourceTeamController, AController* DestinationTeamController);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI", meta=(WorldContext="WorldContextObject"))
	static void KillBots(UObject* WorldContextObject, const bool bKillPlayers, const bool bKillNoneParticipants, const uint8 TeamIndex, AActor* BotOwner);

	UFUNCTION(BlueprintCallable, Category="AI")
	static void MakeBotGroupsTakeEachOtherAsTargets(const TArray<AActor*>& GroupA, const TArray<AActor*>& GroupB, EPerceptionState PerceptionState = EPerceptionState::Threat_Seeing, float ForgetTime = 5.000000f, float ForgetDistance = 2000.000000f);

};

