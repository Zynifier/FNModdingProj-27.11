// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortCreativeTeleporterManagerComponent.generated.h"

class AFortCreativeTeleporter;
enum class EFortCreativeTeleporterGroup : uint8;

UCLASS(Config=Creative, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeTeleporterManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Teleporter")
	const TSet<AFortCreativeTeleporter*> GetTeleportersInGroup(const EFortCreativeTeleporterGroup Group) const;

	UFUNCTION(BlueprintCallable, Category="Teleporter")
	void RegisterTeleporterWithGroup(AFortCreativeTeleporter* TeleporterToRegister, const EFortCreativeTeleporterGroup GroupToRegisterOn);

	UFUNCTION(BlueprintCallable, Category="Teleporter")
	void UnregisterTeleporterFromGroup(AFortCreativeTeleporter* TeleporterToUnregister, const EFortCreativeTeleporterGroup GroupToUnregisterOn);

};

