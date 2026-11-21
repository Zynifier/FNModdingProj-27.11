// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricMetasoundManagerComponent.h"
#include "FabricMetasoundPatchWrapper.h"
#include "FabricMetasoundModulatorPatchWrapper.generated.h"

class UFabricMetaSoundUserOption;
class UPlaylistUserOptionBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFabricMetaSoundModulatorPatchWrapperVisible, bool, bVisible);

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundModulatorPatchWrapper : public UFabricMetaSoundPatchWrapper
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool ConnectToInput(const FFabricMetaSoundNodeInfo& Node, FName InputName, FName InputType);

	UFUNCTION(BlueprintCallable)
	void SetUserOption(UPlaylistUserOptionBase* UserOption);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundModulatorPatchWrapper")
	FName IntModulationOutputName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundModulatorPatchWrapper")
	FName FloatModulationOutputName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundModulatorPatchWrapper")
	FName BoolModulationOutputName;

	UPROPERTY(BlueprintReadOnly, Category="FabricMetaSoundModulatorPatchWrapper")
	FOnFabricMetaSoundModulatorPatchWrapperVisible OnPatchWrapperVisibilityChanged;

private:
	UPROPERTY(Transient)
	TObjectPtr<UPlaylistUserOptionBase> CurrentUserOption;

	UPROPERTY(Transient)
	TObjectPtr<UFabricMetaSoundUserOption> MetaSoundUserOption;

};

