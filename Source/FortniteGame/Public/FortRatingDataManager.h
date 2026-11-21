// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "Online/FortSupervisedSettingsManager.h"
#include "FortRatingDataManager.generated.h"

class UTexture2DDynamic;

USTRUCT(BlueprintType)
struct FAgeRatingDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AgeRatingDisplayData")
	FString AgeRatingId;

	UPROPERTY(BlueprintReadOnly, Category="AgeRatingDisplayData")
	FText AgeRatingText;

	UPROPERTY(BlueprintReadOnly, Category="AgeRatingDisplayData")
	FText AgeRatingTextAbbreviated;

	UPROPERTY()
	bool bNotApplicable;

	UPROPERTY()
	bool bRatingRefused;

	UPROPERTY(BlueprintReadOnly, Category="AgeRatingDisplayData")
	TObjectPtr<UTexture2DDynamic> RatingImageTexture;

	UPROPERTY()
	FString RatingImageURL;

	UPROPERTY(BlueprintReadOnly, Category="AgeRatingDisplayData")
	bool bIsRatingImageRectangular;

	UPROPERTY(BlueprintReadOnly, Category="AgeRatingDisplayData")
	ERatingsBoard RatingBoard;

};

USTRUCT()
struct FInteractiveElementDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString DescriptorId;

	UPROPERTY()
	FText DescriptorText;

};

USTRUCT()
struct FRatingDescriptorDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString DescriptorId;

	UPROPERTY()
	FText DescriptorText;

};

USTRUCT()
struct FRatingBoardDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString RatingBoardId;

	UPROPERTY()
	FText RatingBoardDisplayName;

	UPROPERTY()
	TArray<FAgeRatingDisplayData> AgeRatings;

	UPROPERTY()
	TArray<FRatingDescriptorDisplayData> Descriptors;

};

UCLASS(Config=ServiceBackup)
class UFortRatingDataCache : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TMap<FString, FRatingBoardDisplayData> CachedRegionalBoards;

	UPROPERTY(Config)
	TMap<FString, FInteractiveElementDisplayData> CachedInteractiveElements;

};

UCLASS()
class UFortRatingDataCacheAr : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheDe : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheEs : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheFr : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheIt : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheJa : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheKo : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCachePl : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCachePt : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheRu : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheTr : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheZhCN : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS()
class UFortRatingDataCacheZhTW : public UFortRatingDataCache
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UFortRatingDataManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UTexture2DDynamic>> RatingImages;

};

