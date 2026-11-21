// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortCustomPartTypeEnum.h"
#include "WaitForCosmeticPartApplied.generated.h"

class AFortPlayerPawn;
class UCustomCharacterPart;
class UObject;
class USkeletalMeshComponent;
class UWaitForCosmeticPartApplied;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FWaitForCosmeticPartAppliedPin, AFortPlayerPawn*, Pawn, const UCustomCharacterPart*, Part, USkeletalMeshComponent*, MeshPart, const TEnumAsByte<EFortCustomPartType::Type>, PartType, const TArray<UObject*>&, AnyObjects, const TArray<FString>&, AnyStrings);

UCLASS()
class FORTNITEGAME_API UWaitForCosmeticPartApplied : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(AutoCreateRefTerm="AnyObjects, AnyStrings", BlueprintInternalUseOnly="true", Namespace="Fortnite.Cosmetics", WorldContext="WorldContextObject"))
	static UWaitForCosmeticPartApplied* WaitForCosmeticPartApplied(const UObject* WorldContextObject, AFortPlayerPawn* FortPlayerPawn, bool bSkipNullMesh, const TArray<UObject*>& AnyObjects, const TArray<FString>& AnyStrings);

	UFUNCTION(BlueprintCallable, Category="Cosmetics", meta=(AutoCreateRefTerm="AnyObjects, AnyStrings", BlueprintInternalUseOnly="true", Namespace="Fortnite.Cosmetics", WorldContext="WorldContextObject"))
	static UWaitForCosmeticPartApplied* WaitForCosmeticSpecificPartApplied(const UObject* WorldContextObject, AFortPlayerPawn* FortPlayerPawn, bool bSkipNullMesh, EFortCustomPartType::Type PartType, const TArray<UObject*>& AnyObjects, const TArray<FString>& AnyStrings);

	UPROPERTY(BlueprintAssignable)
	FWaitForCosmeticPartAppliedPin OnPartApplied;

private:
	UFUNCTION()
	void PartApplied(AFortPlayerPawn* Pawn, const UCustomCharacterPart* Part, USkeletalMeshComponent* MeshPart, const EFortCustomPartType::Type PartType);

};

