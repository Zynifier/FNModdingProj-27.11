// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "McpCommandContexts.h"
#include "Online/FortMcpProfile.h"
#include "FortMcpProfileCreative.generated.h"

enum class EFortCreativePlotPermission : uint8;

UENUM()
enum class EPublishStatus : uint8
{
	// NOTE: ordering of these is relevant, be careful!

	Banned = 0,
	CannotPublish = 1,
	NeedsCreatorName = 2,
	CanPublishProvisionally = 3,
	CanPublish = 4,
};

USTRUCT()
struct FFortContentProfile
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortMcpProfileCreative : public UFortMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void CreateNewBattleLabFile(const FString& TemplateId, const FString& Locale, const FString& Title, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execCreateNewBattleLabFile);

	UFUNCTION(ServiceRequest(MCP))
	void CreateNewIsland(const FString& TemplateId, const FString& Locale, const FString& Title, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execCreateNewIsland);

	UFUNCTION(ServiceRequest(MCP))
	void CreateNewIslandFromLinkCode(const FString& LinkCode, const FString& Locale, const FString& Title, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execCreateNewIslandFromLinkCode);

	UFUNCTION(ServiceRequest(MCP))
	void DeleteIsland(const FString& PlotItemId, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execDeleteIsland);

	UFUNCTION(ServiceRequest(MCP))
	void DuplicateIsland(const FString& IslandId, const FString& Locale, const FString& NewTitle, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execDuplicateIsland);

	UFUNCTION(ServiceRequest(MCP))
	void ModifyCreativePlotPermissions(const FString& PlotItemId, EFortCreativePlotPermission Permission, const TArray<FString>& AccountIds, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execModifyCreativePlotPermissions);

	UFUNCTION(ServiceRequest(MCP))
	void RestoreDeletedIsland(const FString& PlotItemId, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execRestoreDeletedIsland);

	UFUNCTION(ServiceRequest(MCP))
	void SetCreativePlotMetadata(const FString& PlotItemId, const FString& Locale, const FString& Title, const FString& Tagline, const TArray<FString>& DescriptionTags, const FString& Introduction, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execSetCreativePlotMetadata);

	UFUNCTION(ServiceRequest(MCP))
	void SetLastUsedCreativePlot(const FString& PlotItemId, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execSetLastUsedCreativePlot);

	UFUNCTION(ServiceRequest(MCP))
	void UpdatePlotBuildCode(const FString& PlotItemId, const FString& BuildCode, int32 BuildCodeVersion, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execUpdatePlotBuildCode);

	UFUNCTION(ServiceRequest(MCP))
	void UpdatePlotPublishInfo(const FString& PlotItemId, const FString& LinkCode, const FString& VkProjectId, const FString& VkModuleId, int32 LinkVersion, const FString& ModerationLinkCode, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execUpdatePlotPublishInfo);

private:
	UPROPERTY(Config)
	bool bEnablePublishing;

	UPROPERTY(Config)
	bool bRequirePublishingPermissions;

};

