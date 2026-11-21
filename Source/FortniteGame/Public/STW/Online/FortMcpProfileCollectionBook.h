// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "McpCommandContexts.h"
#include "Online/FortMcpProfile.h"
#include "FortMcpProfileCollectionBook.generated.h"

UCLASS(BlueprintType)
class UFortMcpProfileCollectionBook : public UFortMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void ClaimCollectionBookPageRewards(const FString& PageTemplateId, const FString& SectionId, int32 SelectedRewardIndex, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimCollectionBookPageRewards);

	UFUNCTION(ServiceRequest(MCP))
	void PromoteItem(const FString& TargetItemId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execPromoteItem);

private:
	UFUNCTION(ServiceRequest(MCP))
	void ConvertSlottedItem(const FString& TargetItemId, int32 ConversionIndex, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execConvertSlottedItem);

	UFUNCTION(ServiceRequest(MCP))
	void UpgradeSlottedItem(const FString& TargetItemId, int32 DesiredLevel, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execUpgradeSlottedItem);

};

