// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GenericTeamAgentInterface.h"
#include "FortNearbyActorsPerceptionComponent.generated.h"

class AActor;
class UFortNearbyActorsPerceptionComponent;

UENUM(meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EFortNearbyActorsTypes : uint8
{
	None = 0,
	// Will return real players

	RealPlayers = 1,
	// Will return bots participating in the match

	Bots = 2,
	// Will return only bots not participating (ex. NPCs, guards, etc.) in the match

	NPCs = 4,
	// Will return only AI Pawns

	AIPawns = 8,
	All = 15,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FBPOnNearbyActorsPerceptionChangedNearbyActors, const TArray<AActor*>&, AllFoundActors, const TArray<AActor*>&, EnteringActors, const TArray<AActor*>&, ExitingActors);

USTRUCT(BlueprintType)
struct FFortNearbyActorsHandle
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortNearbyActorsPerceptionComponent> Owner;

	UPROPERTY(Transient)
	int32 Id;

};

USTRUCT(BlueprintType)
struct FFortNearbyActorsPerceptionConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortNearbyActorsPerceptionConfiguration")
	float MinimumUpdateInterval;

	UPROPERTY(EditAnywhere, Category="FortNearbyActorsPerceptionConfiguration")
	EFortNearbyActorsTypes RequiredTypes;

	UPROPERTY(EditAnywhere, Category="FortNearbyActorsPerceptionConfiguration")
	int32 NumberOfActorsToReturn;

	UPROPERTY(EditAnywhere, Category="FortNearbyActorsPerceptionConfiguration")
	float MinimumDistance;

	UPROPERTY(EditAnywhere, Category="FortNearbyActorsPerceptionConfiguration")
	TArray<TEnumAsByte<ETeamAttitude::Type>> RequiredAttitudes;

	UPROPERTY(EditAnywhere, Category="FortNearbyActorsPerceptionConfiguration")
	bool bRequireLoS;

	UPROPERTY(EditAnywhere, Category="FortNearbyActorsPerceptionConfiguration")
	FGameplayTagQuery RequiredTagsQuery;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortNearbyActorsPerceptionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Query")
	FORTNITEGAME_API FFortNearbyActorsHandle BP_RegisterListener(const FFortNearbyActorsPerceptionConfiguration& Configuration, FBPOnNearbyActorsPerceptionChangedNearbyActors HandleDeltaDelegate);

	UFUNCTION(BlueprintCallable, Category="Query")
	FORTNITEGAME_API static bool BP_UnregisterListener(UPARAM(ref) FFortNearbyActorsHandle& Handle);

	UFUNCTION(BlueprintCallable, Category="Query", meta=(ComponentClass="/Script/FortniteGame.FortNearbyActorsPerceptionComponent", DefaultToSelf="Owner", DeterminesOutputType="ActorComponentClass"))
	FORTNITEGAME_API static UFortNearbyActorsPerceptionComponent* FindOrCreateNearbyActorsPerceptionComponentOnActor(const AActor* Owner, const TSubclassOf<UFortNearbyActorsPerceptionComponent> ActorComponentClass);

};

