// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_EncryptedPluginHelper.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Encrypted Plugin Helper"))
class UFortGameFeatureAction_EncryptedPluginHelper : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Keys")
	TArray<FString> EncryptionKeys;

};

