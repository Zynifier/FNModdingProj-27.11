// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDataUtilityTool/FortAssetDataUtilityTool.h"
#include "FortAssetDataUtilityTool_CollectionTypes.generated.h"

UCLASS(NotBlueprintable, meta=(DisplayName="Add To Local Editor Collection"))
class UFortAssetDataUtilityToolAction_AddToLocalCollection : public UFortAssetDataUtilityToolAction
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static TArray<FName> GetLocalCollectionNames();

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolAction_AddToLocalCollection", meta=(GetOptions="FortniteEditor.FortAssetDataUtilityToolAction_AddToLocalCollection.GetLocalCollectionNames"))
	FName CollectionName;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolAction_AddToLocalCollection")
	bool bCreateCollectionIfNotExist;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolAction_AddToLocalCollection")
	bool bEmptyCollectionBeforeAdd;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolAction_AddToLocalCollection")
	bool bCollectionUpdateFailureIsActionFailure;

};

UCLASS(NotBlueprintable, meta=(DisplayName="In Editor Collection"))
class UFortAssetDataUtilityToolFilter_InCollection : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_InCollection", meta=(GetOptions="FortniteEditor.FortAssetDataUtilityToolGatherer_Collection.GetAllCollectionNames"))
	FName CollectionName;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_InCollection")
	EAssetDataUtilityToolFilterResult CollectionNotFoundBehavior;

};

UCLASS(NotBlueprintable, meta=(DisplayName="Gather From Editor Collection"))
class UFortAssetDataUtilityToolGatherer_Collection : public UFortAssetDataUtilityToolGatherer
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static TArray<FName> GetAllCollectionNames();

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolGatherer_Collection", meta=(GetOptions="FortniteEditor.FortAssetDataUtilityToolGatherer_Collection.GetAllCollectionNames"))
	FName CollectionName;

};

