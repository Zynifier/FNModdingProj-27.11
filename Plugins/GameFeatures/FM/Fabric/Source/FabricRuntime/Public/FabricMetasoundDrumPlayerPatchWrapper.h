// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricMetasoundPatchWrapper.h"
#include "FabricMetasoundDrumPlayerPatchWrapper.generated.h"

class UFabricMetasoundDrumPlayerSampleBankAsset;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFabricMetaSoundDrumPlayerPatchWrapperDrumAmplitudesBinding, const TArray<FFabricMetaSoundPatchWrapperBinding>&, DrumAmplitudes);

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundDrumPlayerPatchWrapper : public UFabricMetaSoundPatchWrapper
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void LoadDrumPlayerSampleBanks(const TArray<TSoftObjectPtr<UFabricMetasoundDrumPlayerSampleBankAsset>>& SampleBankArray, const TSet<int32>& KitNumbersToLoad);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Metasound")
	FName PitchSampleInputName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Metasound")
	FName SlotKitInputName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modulatable")
	TArray<FString> PitchSampleParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modulatable")
	TArray<FString> SlotLinkParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modulatable")
	TArray<FString> SlotUnlinkedKitParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modulatable")
	FString CurrentKitParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modulatable", meta=(ClampMax="8", ClampMin="0"))
	int32 NumSamplesPerKit;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundDrumPlayerPatchWrapper")
	TArray<FFabricMetaSoundPatchWrapperBinding> DrumAmplitudes;

	UPROPERTY(BlueprintAssignable)
	FOnFabricMetaSoundDrumPlayerPatchWrapperDrumAmplitudesBinding OnFabricMetaSoundDrumPlayerPatchDrumAmplitudesUpdate;

private:
	UPROPERTY(Transient)
	TArray<UObject*> CurrentKitSamples;

};

