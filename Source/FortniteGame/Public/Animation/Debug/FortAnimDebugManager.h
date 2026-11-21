// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAnimDebugManager.generated.h"

class AFortPlayerPawn;
class UAnimInstance;
class UFont;
class UFortAnimInstancePropertyDebug;

UCLASS()
class UFortAnimDebugManager : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION(Exec)
	void AddBoneFilter(const FString& Filter);

	UFUNCTION(Exec)
	void AddCurveFilter(const FString& Filter);

	UFUNCTION(Exec)
	bool RemoveBoneFilter(const FString& Filter);

	UFUNCTION(Exec)
	bool RemoveCurveFilter(const FString& Filter);

	UFUNCTION(Exec)
	void ResetBoneFilters();

	UFUNCTION(Exec)
	void ResetCurveFilters();

	UFUNCTION(Exec)
	void ToggleBoneFilter(const FString& Filter);

	UFUNCTION(Exec)
	void ToggleCurveFilter(const FString& Filter);

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(Transient)
	TMap<TSubclassOf<UAnimInstance>, TObjectPtr<UFortAnimInstancePropertyDebug>> AnimInstancePropertyDebugs;

	UPROPERTY()
	TObjectPtr<UFont> MonospaceFont;

};

