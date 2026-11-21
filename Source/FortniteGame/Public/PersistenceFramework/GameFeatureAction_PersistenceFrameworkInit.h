// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_PersistenceFrameworkInit.generated.h"

class UPersistenceFrameworkSubsystemExtension;

USTRUCT()
struct FPFWExtensionToAdd
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Persistence Data")
	TSubclassOf<UPersistenceFrameworkSubsystemExtension> ClassOfExtension;

	UPROPERTY(EditAnywhere, Category="Persistence Data")
	bool bLeaveActiveOnDeactivate;

};

UCLASS(meta=(DisplayName="Persistence Framework Extensions"))
class FORTNITEGAME_API UGameFeatureAction_PersistenceFrameworkInit : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Persistence Data")
	TArray<FPFWExtensionToAdd> ExtensionsToAdd;

};

