// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricMetasoundPatchWrapper.h"
#include "FabricMetasoundWetDryPatchWrapper.generated.h"

USTRUCT(BlueprintType)
struct FFabricMetaSoundPatchWrapperWetDryOutputBinding
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapperWetDryOutputBinding")
	FFabricMetaSoundPatchWrapperBinding WetOutputSignalBinding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapperWetDryOutputBinding")
	FFabricMetaSoundPatchWrapperBinding DryOutputSignalBinding;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFabricMetaSoundPatchWrapperWetDryOutputBinding, const FFabricMetaSoundPatchWrapperWetDryOutputBinding&, WetDryOutputBindings);

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundWetDryPatchWrapper : public UFabricMetaSoundPatchWrapper
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundWetDryPatchWrapper")
	FFabricMetaSoundPatchWrapperWetDryOutputBinding WetDryOutputBinding;

	UPROPERTY(BlueprintAssignable)
	FOnFabricMetaSoundPatchWrapperWetDryOutputBinding OnWetDryOutputSignalUpdate;

};

