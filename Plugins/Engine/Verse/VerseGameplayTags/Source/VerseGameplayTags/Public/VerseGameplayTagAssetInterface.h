// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseGameplayTag.h"
#include "VerseGameplayTagContainer.h"
#include "VerseGameplayTagAssetInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UVerseGameplayTagAssetInterface : public UInterface
{
	GENERATED_BODY()
};

class IVerseGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	/**
	 * Get any owned gameplay tags on the asset
	 * 
	 * @param OutTags	[OUT] Set of tags on the asset
	 */
	UFUNCTION(Category="GameplayTags")
	virtual void GetOwnedGameplayTags(FVerseGameplayTagContainer& TagContainer) const;

	/**
	 * Check if the asset has gameplay tags that matches against all of the specified tags (expands to include parents of asset tags)
	 * 
	 * @param TagContainer			Tag container to check for a match
	 * 
	 * @return True if the asset has matches all of the gameplay tags, will be true if container is empty
	 */
	UFUNCTION(Category="GameplayTags")
	virtual bool HasAllMatchingGameplayTags(const FVerseGameplayTagContainer& TagContainer) const;

	/**
	 * Check if the asset has gameplay tags that matches against any of the specified tags (expands to include parents of asset tags)
	 * 
	 * @param TagContainer			Tag container to check for a match
	 * 
	 * @return True if the asset has matches any of the gameplay tags, will be false if container is empty
	 */
	UFUNCTION(Category="GameplayTags")
	virtual bool HasAnyMatchingGameplayTags(const FVerseGameplayTagContainer& TagContainer) const;

	/**
	 * Check if the asset has a gameplay tag that matches against the specified tag (expands to include parents of asset tags)
	 * 
	 * @param TagToCheck	Tag to check for a match
	 * 
	 * @return True if the asset has a gameplay tag that matches, false if not
	 */
	UFUNCTION(Category="GameplayTags")
	virtual bool HasMatchingGameplayTag(FVerseGameplayTag TagToCheck) const;

};

