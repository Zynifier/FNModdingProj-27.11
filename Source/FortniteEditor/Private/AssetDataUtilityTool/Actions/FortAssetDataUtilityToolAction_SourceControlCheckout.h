// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDataUtilityTool/FortAssetDataUtilityTool.h"
#include "FortAssetDataUtilityToolAction_SourceControlCheckout.generated.h"

UENUM()
enum class EFortActionSourceControlCheckoutSuccessCriteria : uint8
{
	// Action always reports success, even if internal errors occur

	AlwaysSucceed = 0,
	// For action to report successful, when execution is finished all assets must either be:
// * checked out
// * Local Only file not in source 
// Otherwise action will return failure.

	AllAssetsCheckedOutOrLocalOnly = 1,
};

UCLASS(meta=(DisplayName="Source Control Checkout"))
class UFortAssetDataUtilityToolAction_SourceControlCheckout : public UFortAssetDataUtilityToolAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolAction_SourceControlCheckout")
	EFortActionSourceControlCheckoutSuccessCriteria SuccessCriteria;

};

