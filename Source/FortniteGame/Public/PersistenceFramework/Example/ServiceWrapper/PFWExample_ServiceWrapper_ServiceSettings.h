// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/Example/ServiceWrapper/PFWExample_ServiceWrapper.h"
#include "PersistenceFramework/PersistenceFrameworkServiceSettingsBase.h"
#include "PFWExample_ServiceWrapper_ServiceSettings.generated.h"

UCLASS()
class FORTNITEGAME_API UPFWExample_ServiceWrapper_ServiceSettings : public UPersistenceFrameworkServiceSettingsBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PFWExample_ServiceWrapper_ServiceSettings")
	FPFWExample_ServiceWrapper_Settings Setting;

};

