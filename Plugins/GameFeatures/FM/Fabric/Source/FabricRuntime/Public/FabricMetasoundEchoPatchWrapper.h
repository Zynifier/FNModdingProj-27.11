// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricMetasoundWetDryPatchWrapper.h"
#include "FabricMetasoundEchoPatchWrapper.generated.h"

class UFabricWaveformTexture;

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundEchoPatchWrapper : public UFabricMetaSoundWetDryPatchWrapper
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FabricMetaSoundEchoPatchWrapper")
	bool bAllowWetSignalWaveformTexture;

	UPROPERTY(EditDefaultsOnly, Category="FabricMetaSoundEchoPatchWrapper")
	bool bAllowDrySignalWaveformTexture;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricMetaSoundEchoPatchWrapper")
	TObjectPtr<UFabricWaveformTexture> WetSignalWaveformTexture;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricMetaSoundEchoPatchWrapper")
	TObjectPtr<UFabricWaveformTexture> DrySignalWaveformTexture;

};

