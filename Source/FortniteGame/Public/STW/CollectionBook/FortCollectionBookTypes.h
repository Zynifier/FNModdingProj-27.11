// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTypes.h"
#include "FortCollectionBookTypes.generated.h"

UENUM(BlueprintType)
enum class ECollectionBookRewardType : uint8
{
	/* Invalid reward type */
	Uninitialized = 0,
	/* The reward is for advancing the book xp to the next level reward */
	Book = 1,
	/* The reward is for completing a page */
	Page = 2,
	/* The reward is for completing a section */
	Section = 3,
};

UENUM(BlueprintType)
enum class EFortCollectionBookState : uint8
{
	/** In-progress state */
	Active = 0,
	/** All the slots filled, but rewards not yet claimed */
	Completed = 1,
	/** Page or section completed and rewards claimed */
	Claimed = 2,
};

USTRUCT(BlueprintType)
struct FFortCollectionBookRewards
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookRewards")
	ECollectionBookRewardType RewardType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookRewards")
	FName PageId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookRewards")
	FName SectionId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookRewards")
	int32 XpRequired;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookRewards")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookRewards")
	bool bIsMajorReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCollectionBookRewards")
	FFortRewardInfo Rewards;

};

USTRUCT()
struct FFortCollectionBookSectionState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Section;

	UPROPERTY()
	EFortCollectionBookState State;

};

