// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "UObject/NoExportTypes.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortItemVariantHandle.h"
#include "FortPlayerCustomizableInterface.h"
#include "FortPropertyOverrideData.h"
#include "FortRarityEnum.h"
#include "FortUserOptionValues.h"
#include "FortCreativeItemTemplate.generated.h"

class UFortCreativeItemTemplate;

USTRUCT(BlueprintType)
struct FCreativeItemTemplateData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Category="CreativeItemTemplateData")
	FItemVariantHandle VariantHandle;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeItemTemplateData")
	FGuid SourceItemVariantGuid;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeItemTemplateData")
	FGameplayTagContainer SourceTags;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeItemTemplateData")
	UFortCreativeItemTemplate* TemplateObject;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeItemTemplateData")
	FPropertyOverrideData ItemOptionData;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeItemTemplateData")
	bool bEnabled;

};

USTRUCT()
struct FCreativeItemTemplate : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Transient, Category="CreativeItemTemplate")
	int32 TrackedIndex;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeItemTemplate")
	FCreativeItemTemplateData TemplateData;

	UPROPERTY(VisibleInstanceOnly, Transient, NotReplicated, Category="CreativeItemTemplate")
	TObjectPtr<UFortCreativeItemTemplate> TemplateObj;

	UPROPERTY(Transient, NotReplicated)
	uint32 PrevOptionDataHash;

	UPROPERTY(Transient, NotReplicated)
	FItemVariantHandle PrevVariantHandle;

};

USTRUCT()
struct FCreativeItemTemplateDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Transient, Category="CreativeItemTemplateDataArray")
	TArray<FCreativeItemTemplate> ItemTemplates;

};

USTRUCT()
struct FCreativeItemVariantAggregate
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, SparseClassDataType=UserOptionDefinitionContainer, meta=(ShowWorldContextPin))
class UFortCreativeItemTemplate : public UObject, public IFortPlayerCustomizable, public IGameplayTagAssetInterface, public IUserOptionValuesInterface, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Category="FortCreativeItemTemplate")
	int32 TrackedIndex;

	UPROPERTY(Transient)
	FGameplayTagContainer SourceTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeItemTemplate")
	FItemVariantHandle VariantHandle;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Item Template")
	bool bEnabled;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativeItemTemplate")
	bool bUseInternalOptionDefinitions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="UserOptions|Basic")
	FString DisplayName;

	UPROPERTY(EditAnywhere, SaveGame, Category="UserOptions|Basic")
	EFortRarity Rarity;

	UPROPERTY(Transient)
	int32 MaxRegenStacks;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeItemTemplate")
	bool bShouldGenerateUserOptionConfig;

};

