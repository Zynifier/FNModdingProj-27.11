// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "McpCommandContexts.h"
#include "Online/FortMcpProfile.h"
#include "STW/Items/FortOutpostItemDefinition.h"
#include "FortMcpProfileMetadata.generated.h"

UCLASS()
class UFortMcpProfileMetadata : public UFortMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void CreateDeployableBaseItem(const FString& TemplateId, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execCreateDeployableBaseItem);

	UFUNCTION(ServiceRequest(MCP))
	void CreateOrUpgradeOutpostItem(const FString& templateId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execCreateOrUpgradeOutpostItem);

	UFUNCTION(ServiceRequest(MCP))
	void UpdateDeployableBaseTierProgression(const FString& DeployableBaseItemId, const FString& ProgressionLayoutGuid, int32 TierDefeated, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execUpdateDeployableBaseTierProgression);

	UFUNCTION(ServiceRequest(MCP))
	void UpdateOutpostCore(const FString& CoreId, const FFortOutpostCoreInfo& CoreInfo, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execUpdateOutpostCore);

};

