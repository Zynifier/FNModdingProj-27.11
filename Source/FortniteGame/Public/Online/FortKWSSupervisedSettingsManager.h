// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortMcpUtils.h"
#include "Online/FortSupervisedSettingsManager.h"
#include "FortKWSSupervisedSettingsManager.generated.h"

UCLASS()
class UFortKWSSupervisedSettingsManager : public UFortSupervisedSettingsManager
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPrivacySettingsReadComplete(bool bSuccess, const FMcpPrivacySettings& PrivacySettings);

	UFUNCTION()
	void UpdateKWSForIndividualSettingsIfNeeded();

};

