// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortFactionMapping.generated.h"

UENUM(BlueprintType)
namespace EFortFactionAttitude
{
	enum Type
	{
		Friendly = 0,
		Neutral = 1,
		Hostile = 2,
		MAX = 3 UMETA(DisplayName="Invalid", Hidden),
	};
}

USTRUCT(BlueprintType)
struct FFactionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	bool bActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Description")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Description")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Description", meta=(Categories="Athena.Faction"))
	FGameplayTag FactionTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Relations")
	TEnumAsByte<EFortFactionAttitude::Type> DefaultAttitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Relations")
	bool bAreFactionMemberAllies;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Relations")
	bool bShouldSpecificRelationsApplyToEntireFaction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Relations", meta=(EditCondition="!bShouldSpecificRelationsApplyToEntireFaction"))
	bool bMembersCanResetSpecificRelation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Relations", meta=(EditCondition="!bShouldSpecificRelationsApplyToEntireFaction && bMembersCanResetSpecificRelation"))
	FScalableFloat ResetSpecificRelationUnawareDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Relations", meta=(EditCondition="!bShouldSpecificRelationsApplyToEntireFaction && bMembersCanResetSpecificRelation"))
	FScalableFloat ResetSpecificRelationNoDamageDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Relations", meta=(EditCondition="!bShouldSpecificRelationsApplyToEntireFaction"))
	bool bConditionallyApplyRelationsToAdditionalFactionMembers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Relations", meta=(EditCondition="bConditionallyApplyRelationsToAdditionalFactionMembers"))
	FScalableFloat MaxDistanceCondition;

	UPROPERTY(EditAnywhere, Category="Relations", meta=(ArraySizeEnum="/Script/FortniteGame.EFortFactionAttitude", Categories="Athena.Faction"))
	FGameplayTagContainer RelationExceptions[3];

	UPROPERTY(EditAnywhere, Category="Relations", meta=(Categories="Athena.Faction"))
	FGameplayTagContainer AllowFriendlyFireAgainstFactions;

};

UCLASS()
class UFortFactionMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Faction")
	FGameplayTagContainer BlockResetSpecificRelationTags;

	UPROPERTY(EditAnywhere, Category="Faction", meta=(TitleProperty="Name"))
	TArray<FFactionData> FactionDataArray;

};

