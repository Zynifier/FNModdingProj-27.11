// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "McpCommandContexts.h"
#include "Online/FortMcpProfile.h"
#include "Quests/FortQuestTypes.h"
#include "FortMcpProfileSubgame.generated.h"

class UFortCosmeticLockerItem;
enum class EAthenaCustomizationCategory : uint8;

USTRUCT()
struct FFortAthenaLoadoutData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAthenaCustomizationCategory Category;

	UPROPERTY()
	FString ItemToSlot;

	UPROPERTY()
	int32 SlotIndex;

	UPROPERTY()
	TArray<FMcpVariantReader> VariantUpdates;

};

USTRUCT()
struct FFortSubgameClientSettings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> PinnedQuestInstances;

};

UCLASS(MinimalAPI)
class UFortMcpProfileSubgame : public UFortMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void ClaimQuestReward(const FString& QuestId, int32 SelectedRewardIndex, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimQuestReward);

	UFUNCTION(ServiceRequest(MCP))
	void ClientQuestLogin(const FString& StreamingAppKey, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClientQuestLogin);

	UFUNCTION(ServiceRequest(MCP))
	void CopyCosmeticLoadout(int32 SourceIndex, int32 TargetIndex, const FString& OptNewNameForTarget, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execCopyCosmeticLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void FortRerollDailyQuest(const FString& QuestId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execFortRerollDailyQuest);

	UFUNCTION(ServiceRequest(MCP))
	void MarkNewQuestNotificationSent(const TArray<FString>& ItemIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execMarkNewQuestNotificationSent);

	UFUNCTION(ServiceRequest(MCP))
	void ServerQuestLogin(const FString& MatchmakingSessionId, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execServerQuestLogin);

	UFUNCTION(ServiceRequest(MCP))
	void SetCosmeticLockerBanner(const FString& LockerItem, const FString& BannerIconTemplateName, const FString& BannerColorTemplateName, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetCosmeticLockerBanner);

	UFUNCTION(ServiceRequest(MCP))
	void SetCosmeticLockerName(const FString& LockerItem, const FString& Name, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetCosmeticLockerName);

	UFUNCTION(ServiceRequest(MCP))
	void SetCosmeticLockerSlot(const FString& LockerItem, EAthenaCustomizationCategory Category, const FString& ItemToSlot, int32 SlotIndex, const TArray<FMcpVariantReader>& VariantUpdates, int32 OptLockerUseCountOverride, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetCosmeticLockerSlot);

	UFUNCTION(ServiceRequest(MCP))
	void SetCosmeticLockerSlots(const FString& LockerItem, const TArray<FFortAthenaLoadoutData>& LoadoutData, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetCosmeticLockerSlots);

	UFUNCTION(ServiceRequest(MCP))
	void SetItemArchivedStatusBatch(const TArray<FString>& ItemIds, bool archived, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetItemArchivedStatusBatch);

	UFUNCTION(ServiceRequest(MCP))
	void SetItemFavoriteStatus(const FString& TargetItemId, bool bFavorite, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetItemFavoriteStatus);

	UFUNCTION(ServiceRequest(MCP))
	void SetItemFavoriteStatusBatch(const TArray<FString>& ItemIds, const TArray<bool>& itemFavStatus, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetItemFavoriteStatusBatch);

	UFUNCTION(ServiceRequest(MCP))
	void SetRandomCosmeticLoadoutFlag(bool Random, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetRandomCosmeticLoadoutFlag);

	UFUNCTION(ServiceRequest(MCP))
	void UpdateQuestClientObjectives(const TArray<FFortQuestObjectiveCompletion>& Advance, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUpdateQuestClientObjectives);

	UFUNCTION(ServiceRequest(MCP))
	void UpdateQuests(const TArray<FFortQuestObjectiveCompletion>& Advance, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execUpdateQuests);

protected:
	UFUNCTION(ServiceRequest(MCP))
	void DeleteCosmeticLoadout(int32 Index, int32 FallbackLoadoutIndex, bool leaveNullSlot, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execDeleteCosmeticLoadout);

	UFUNCTION(ServiceRequest(MCP))
	void SetPinnedQuests(const TArray<FString>& PinnedQuestIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetPinnedQuests);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortCosmeticLockerItem>> LoadoutLockerItems;

	UPROPERTY(Transient)
	TObjectPtr<UFortCosmeticLockerItem> LastAppliedLoadout;

	UPROPERTY(Transient)
	int32 LastAppliedLoadoutIndex;

private:
	UPROPERTY()
	FFortSubgameClientSettings CachedClientSettings;

};

