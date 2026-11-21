// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "FortCreativeTags.generated.h"

class UDataTable;
class UFortItemDefinition;
class UTexture2D;

USTRUCT()
struct FFortCreativeTag : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCreativeTag")
	FText Name;

	UPROPERTY(EditAnywhere, Category="FortCreativeTag")
	FName Category;

	UPROPERTY(EditAnywhere, Category="FortCreativeTag")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, Category="FortCreativeTag")
	float SortPriority;

	UPROPERTY(EditAnywhere, Category="FortCreativeTag")
	bool bNonCosmetic;

};

USTRUCT()
struct FFortCreativeTagCategory : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCreativeTagCategory")
	FText Name;

	UPROPERTY(EditAnywhere, Category="FortCreativeTagCategory")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, Category="FortCreativeTagCategory")
	float SortPriority;

};

USTRUCT()
struct FFortCreativeTagsHelper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCreativeTagsHelper", meta=(NoResetToDefault))
	TArray<FName> CreativeTags;

};

UINTERFACE(MinimalAPI)
class UFortCreativeTagsBearer : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortCreativeTagsBearer
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortCreativeTagsManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static FText GetCreativeTagTextForID(const FName& TagID);

	UFUNCTION(BlueprintCallable)
	static TArray<FName> GetUserVisibleTagIDsForItem(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable)
	static TArray<FText> GetUserVisibleTagsForItem(const UFortItemDefinition* ItemDefinition);

private:
	UPROPERTY(Transient)
	TObjectPtr<UDataTable> CreativeTagsTable;

	UPROPERTY(Transient)
	TObjectPtr<UDataTable> CreativeTagCategoriesTable;

};

