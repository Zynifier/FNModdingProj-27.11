// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Faction/FortFactionMapping.h"
#include "FortFactionInfo.generated.h"

class UBlackboardComponent;
class UFortActorComponent_Affiliation;

USTRUCT()
struct FFortAffiliationActorIdentifierList
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<uint32> AffiliationComponentUIDs;

};

USTRUCT()
struct FFortFactionSharedBBInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortActorComponent_Affiliation>> Members;

	UPROPERTY(Transient)
	FGameplayTag BlackboardTag;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBlackboardComponent> BlackboardComp;

};

USTRUCT()
struct FFortFactionInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTag FactionTag;

	UPROPERTY(Transient)
	TEnumAsByte<EFortFactionAttitude::Type> DefaultAttitude;

	UPROPERTY(Transient)
	uint8 bHasSpecificRelations : 1;

	UPROPERTY(Transient)
	uint8 bAreFactionMemberAllies : 1;

	UPROPERTY(Transient)
	uint8 bShouldSpecificRelationsApplyToEntireFaction : 1;

	UPROPERTY(Transient)
	uint8 bMembersCanResetSpecificRelation : 1;

	UPROPERTY(Transient)
	float ResetSpecificRelationUnawareDelay;

	UPROPERTY(Transient)
	float ResetSpecificRelationNoDamageDelay;

	UPROPERTY(Transient)
	uint8 bConditionallyApplyRelationsToAdditionalFactionMembers : 1;

	UPROPERTY(Transient)
	float MaxDistanceCondition;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortFactionAttitude"))
	FGameplayTagContainer FactionRelations[3];

	UPROPERTY(Transient)
	FGameplayTagContainer AllowFriendlyFireAgainstFactions;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortFactionAttitude"))
	FFortAffiliationActorIdentifierList SpecificRelations[3];

	UPROPERTY(Transient, NotReplicated, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortActorComponent_Affiliation>> Members;

	UPROPERTY(Transient, NotReplicated)
	TArray<FFortFactionSharedBBInfo> SharedBBInfos;

};

