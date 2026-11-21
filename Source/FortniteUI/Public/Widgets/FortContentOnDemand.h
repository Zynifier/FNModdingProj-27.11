// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Timespan.h"
#include "FortGameFeatureEnum.h"
#include "FortHUDElementWidget.h"
#include "FortContentOnDemand.generated.h"

class UAthenaCosmeticItemDefinition;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortContentOnDemand : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatedState(int32 NumActiveDownloads, int32 NumErrors);

	UPROPERTY(EditAnywhere, Category="FortContentOnDemand")
	float ReEnableSettingDelay;

	UPROPERTY(Config)
	bool bEnabled;

	UPROPERTY(Config)
	bool bWidgetEnabled;

	UPROPERTY(Config)
	int64 LastReminder;

	UPROPERTY(Config)
	FTimespan TimespanToRemind;

	UPROPERTY(Config)
	bool bSendErrorReports;

	UPROPERTY(Config)
	bool bSendOutOfMemoryErrorReports;

	UPROPERTY(Config)
	TArray<EFortGameFeature> GameFeaturesToListenFor_Config;

	UPROPERTY(EditAnywhere, Category="FortContentOnDemand")
	TArray<EFortGameFeature> GameFeaturesToListenFor;

	UPROPERTY(Config)
	TArray<EFortGameFeature> OptionalGameFeaturesToListenFor_Config;

	UPROPERTY(EditAnywhere, Category="FortContentOnDemand")
	TArray<EFortGameFeature> OptionalGameFeaturesToListenFor;

private:
	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UAthenaCosmeticItemDefinition>> ActiveCosmeticDownloads;

};

