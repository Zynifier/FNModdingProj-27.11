// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortUserOptionDefinitions.h"
#include "FortCreativeAssetOption.generated.h"

class UDataTable;
class UObject;

USTRUCT(BlueprintType)
struct FUserOptionAssetReference
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UserOptionAssetReference")
	TSoftObjectPtr<UObject> AssetRef;

};

USTRUCT()
struct FUserOptionAssetTypeMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UserOptionAssetTypeMetaData", meta=(AllowAbstract))
	TSubclassOf<UObject> AssetClass;

	UPROPERTY(EditDefaultsOnly, Category="UserOptionAssetTypeMetaData")
	TArray<TSubclassOf<UObject>> AllowedClasses;

	UPROPERTY(EditDefaultsOnly, Category="UserOptionAssetTypeMetaData")
	TArray<TSubclassOf<UObject>> DisallowedClasses;

	UPROPERTY(EditDefaultsOnly, Category="UserOptionAssetTypeMetaData")
	bool bExactClass;

	UPROPERTY(EditDefaultsOnly, Category="UserOptionAssetTypeMetaData")
	bool bSoftReference;

};

USTRUCT(BlueprintType)
struct FUserOptionClassReference
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UserOptionClassReference")
	TSoftClassPtr<UObject> ClassRef;

};

USTRUCT()
struct FUserOptionClassTypeMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UserOptionClassTypeMetaData")
	bool bSoftReference;

	UPROPERTY(EditDefaultsOnly, Category="UserOptionClassTypeMetaData")
	TSubclassOf<UObject> MetaClass;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionActorReferenceMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionAssetValueEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FUserOptionAssetReference Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionAssetReferenceMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category="OptionMetaData")
	FUserOptionAssetTypeMetaData AssetType;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(AssetTypeMetaProperty="AssetType"))
	FUserOptionAssetReference DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.UserOptionDefinitionAssetValueEntry"))
	TObjectPtr<UDataTable> ValuesDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(AssetTypeMetaProperty="AssetType"))
	TArray<FUserOptionDefinitionAssetValueEntry> ValueEntries;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bIsArrayProperty;
#endif

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionClassReferenceValueEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FUserOptionClassReference Value;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(Categories="Creative"))
	FGameplayTagContainer GrantedContextTags;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionClassReferenceMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category="OptionMetaData")
	FUserOptionClassTypeMetaData ClassType;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(AssetTypeMetaProperty="ClassType"))
	FUserOptionClassReference DefaultValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.FUserOptionDefinitionClassReferenceValueEntry"))
	TObjectPtr<UDataTable> ValuesDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData", meta=(AssetTypeMetaProperty="ClassType"))
	TArray<FUserOptionDefinitionClassReferenceValueEntry> ValueEntries;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bIsArrayProperty;
#endif

};

