// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Items/FortAccountItem.h"
#include "OnlineLinkId.h"
#include "FortCreativeRealEstatePlotItem.generated.h"

UENUM(BlueprintType)
enum class EFortCreativePlotPermission : uint8
{
	Private = 0,
	Public = 1,
};

USTRUCT(BlueprintType)
struct FFortCreativeAllowedUserEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativeAllowedUserEntry")
	FString UniqueID;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeAllowedUserEntry")
	FString UserName;

};

USTRUCT(BlueprintType)
struct FFortCreativePlotPermissionData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativePlotPermissionData")
	EFortCreativePlotPermission Permission;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativePlotPermissionData")
	TArray<FString> Whitelist;

};

UCLASS(MinimalAPI)
class UFortCreativeRealEstatePlotItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 IslandIndex;

	UPROPERTY()
	FString IslandInfoLocale;

	UPROPERTY()
	FString IslandTitle;

	UPROPERTY()
	FString IslandTagline;

	UPROPERTY()
	TArray<FString> DescriptionTags;

	UPROPERTY()
	FOnlineLinkId IslandLinkId;

	UPROPERTY()
	FOnlineLinkId IslandBuildLinkId;

	UPROPERTY()
	FString ModerationCode;

	UPROPERTY()
	FString VkProjectId;

	UPROPERTY()
	FString VkModuleId;

	UPROPERTY()
	bool bIsPromoted;

	UPROPERTY()
	bool bShouldHeartify;

	UPROPERTY()
	FString IslandIntroduction;

	UPROPERTY()
	FDateTime LastPublishedDate;

	UPROPERTY()
	FDateTime LastUsedDate;

	UPROPERTY()
	FFortCreativePlotPermissionData PermissionData;

	UPROPERTY()
	FDateTime DeletedAt;

};

