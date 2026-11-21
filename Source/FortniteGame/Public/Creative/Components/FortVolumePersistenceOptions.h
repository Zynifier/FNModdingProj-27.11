// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortVolumePersistenceOptions.generated.h"

class UFortCreativePersistenceComponent;

USTRUCT(BlueprintType)
struct FFortCreativePersistenceOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativePersistenceOptions")
	bool bAllowPlayerToClearData;

};

UCLASS()
class UFortVolumePersistenceOptions : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const UFortCreativePersistenceComponent* GetFirstOrderedPersistenceComponent() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerClearDataOptionAllowed() const;

	UFUNCTION(BlueprintPure)
	bool IsTherePersistenceDevices() const;

	UFUNCTION(BlueprintCallable)
	void RegistryFortCreativePersistenceComponent(const UFortCreativePersistenceComponent* FortCreativePersistenceComponent, const FFortCreativePersistenceOptions& FortCreativePersistenceOptions);

	UFUNCTION(BlueprintCallable)
	void UnregistryFortCreativePersistenceComponent(const UFortCreativePersistenceComponent* FortCreativePersistenceComponent);

	UFUNCTION(BlueprintCallable)
	void UpdatePersistenceComponent(const UFortCreativePersistenceComponent* FortCreativePersistenceComponent, const FFortCreativePersistenceOptions& FortCreativePersistenceOptions);

private:
	UPROPERTY(Transient, Replicated)
	uint8 bAllowPlayerToClearData : 1;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UFortCreativePersistenceComponent>, FFortCreativePersistenceOptions> FortCreativePersistenceOptionsMap;

};

