// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortCreativeDiscoverySurface.generated.h"

UENUM(BlueprintType)
enum class EFortCreativeDiscoveryDeterminism : uint8
{
	/** Always select. */
	Always = 0,
	/** Randomly select. */
	Random = 1,
	/** Deterministically select based on the player ID. */
	PlayerDeterministic = 2,
	/** Deterministically select based on the party player IDs. */
	PartyDeterministic = 3,
	/** Epic Employees will always be entered into this cohort. */
	EpicEmployee = 4,
	/** Never select. */
	Never = 5,
};

UENUM(BlueprintType)
enum class EFortCreativeDiscoveryPanelOrdering : uint8
{
	/** The panel is in a locked position. */
	Locked = 0,
	/** The panel may be freely re-ordered with other Floating content panels. */
	Floating = 1,
};

UENUM(BlueprintType)
enum class EFortCreativeDiscoveryPanelType : uint8
{
	/** The content is selected from a sequential list of pre-defined entries. */
	CuratedList = 0,
	/** The content is selected based on the result set of a metrtic. */
	MetricDriven = 1,
	/** The content is selected per user from the recommendation system. */
	Recommendations = 2,
	/** The content is selected based on the player's recently and favorited links. */
	PlayHistory = 3,
	/** The content is selected from a backend analytical data table that was processed separately. */
	AnalyticsList = 4,
	/** The content is selected from a backend call to Event Service that determines tournaments the player is eligible for */
	Tournaments = 5,
};

UENUM(BlueprintType)
enum class EFortCreativeDiscoveryPlayHistoryType : uint8
{
	/** Only recently played links are shown, sorted by interaction date. */
	RecentlyPlayed = 0,
	/** Only favorite links are shown, interaction date. */
	Favorites = 1,
	/** Both recently played and favorite links are shown, sorted by interaction date. */
	RecentlyPlayedAndFavorites = 2,
	/** Only queued links are shown, sorted by interaction date. */
	Queued = 3,
};

UENUM(BlueprintType)
enum class EFortCreativeDiscoverySkippedEntries : uint8
{
	/** Never skip over entries. */
	None = 0,
	/** Skip over an exact amount of entries. */
	ByCount = 1,
	/** Skip over the percent [0, 1] of top results. */
	ByPercent = 2,
};

USTRUCT(BlueprintType)
struct FFortCreativeDiscoverySplicedEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySplicedEntry")
	FName EntryName;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySplicedEntry")
	int32 EntryIndex;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySplicedEntry")
	FString LinkCode;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySplicedEntry")
	EFortCreativeDiscoveryDeterminism VisibilitySelector;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySplicedEntry")
	float VisibilityChance;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySplicedEntry")
	bool bPushDownExistingEntry;

};

USTRUCT(BlueprintType)
struct FFortCreativeDiscoveryContentPanel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Panel")
	FName PanelName;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	FText PanelDisplayName;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	EFortCreativeDiscoveryPanelType PanelType;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	EFortCreativeDiscoveryPanelOrdering PanelOrdering;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	int32 PageSize;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	int32 NumPages;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FString> PlatformWhitelist;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FString> PlatformBlacklist;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FString> MMRegionAllowlist;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FString> MMRegionBlocklist;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FString> CountryCodeAllowlist;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FString> CountryCodeBlocklist;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FString> PanelLinkCodeBlacklist;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FString> PanelLinkCodeWhitelist;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	EFortCreativeDiscoverySkippedEntries EntrySkippingMethod;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	int32 SkippedEntriesCount;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	float SkippedEntriesPercent;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	TArray<FName> FeatureTags;

	UPROPERTY(EditDefaultsOnly, Category="Panel")
	FString AnalyticsId;

	UPROPERTY(EditDefaultsOnly, Category="Curation")
	TArray<FString> CuratedListOfLinkCodes;

	UPROPERTY(EditDefaultsOnly, Category="Metrics")
	FString MetricName;

	UPROPERTY(EditDefaultsOnly, Category="Metrics")
	FString MetricInterval;

	UPROPERTY(EditDefaultsOnly, Category="Metrics")
	bool bLowestToHighest;

	UPROPERTY(EditDefaultsOnly, Category="Recommendations")
	FString ModelName;

	UPROPERTY(EditDefaultsOnly, Category="Play History")
	EFortCreativeDiscoveryPlayHistoryType PlayHistoryType;

	UPROPERTY(EditDefaultsOnly, Category="Analytics List")
	FString AnalyticsListName;

	UPROPERTY(EditDefaultsOnly, Category="Splicing")
	TArray<FFortCreativeDiscoverySplicedEntry> SplicedEntries;

};

USTRUCT(BlueprintType)
struct FFortCreativeDiscoveryTestCohort
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	FName TestName;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	FString CategoryRecommendationModelName;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	EFortCreativeDiscoveryDeterminism CohortSelector;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	float SelectionChance;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	TArray<FString> PlatformWhitelist;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	TArray<FString> PlatformBlacklist;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	TArray<FString> MMRegionAllowlist;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	TArray<FString> MMRegionBlocklist;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	TArray<FString> CountryCodeAllowlist;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	TArray<FString> CountryCodeBlocklist;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	TArray<FFortCreativeDiscoveryContentPanel> ContentPanels;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoveryTestCohort")
	FString AnalyticsId;

};

UCLASS()
class UFortCreativeDiscoverySurface : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySurface", meta=(Patchable))
	FName SurfaceName;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySurface", meta=(Patchable))
	FName TestName;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySurface", meta=(Patchable))
	TArray<FFortCreativeDiscoveryTestCohort> TestCohorts;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySurface", meta=(Patchable))
	TArray<FString> GlobalLinkCodeBlacklist;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySurface", meta=(Patchable))
	TArray<FString> GlobalLinkCodeWhitelist;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDiscoverySurface", meta=(Patchable))
	FString AnalyticsId;

	UPROPERTY(Transient)
	bool bIsResolvedDataDirty;

	UPROPERTY(Transient)
	bool bHasResolvedData;

	UPROPERTY(Transient)
	int32 ResolvedRevision;

	UPROPERTY(Transient)
	TArray<FName> ResolvedPanelOrder;

	UPROPERTY(Transient)
	TArray<FName> ResolvedTestCohortNames;

};

