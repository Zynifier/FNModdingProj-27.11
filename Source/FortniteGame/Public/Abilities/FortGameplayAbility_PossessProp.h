// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayAbility_Action.h"
#include "FortGameplayAbility_PossessProp.generated.h"

class ABuildingActor;
class UDataTable;

USTRUCT(BlueprintType)
struct FPossessPropClasses : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PossessPropClasses", meta=(AllowAbstract))
	TSoftClassPtr<ABuildingActor> ClassPath;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PossessPropClasses")
	float PreviewScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PossessPropClasses")
	FRotator PossessedRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PossessPropClasses")
	FVector PossessedScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PossessPropClasses")
	FText CategoryLabelText;

};

UCLASS()
class UFortGameplayAbility_PossessProp : public UFortGameplayAbility_Action
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="RiftBubble")
	TSubclassOf<ABuildingActor> GetAllowedPropClassByIndex(int32 AllowedPropIndex) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="RiftBubble")
	FPossessPropClasses GetAllowedPropDataByIndex(int32 AllowedPropIndex) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="RiftBubble")
	float GetPreviewScaleByIndex(int32 AllowedPropIndex) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="RiftBubble")
	void SetAllowedPropTable(UDataTable* InAllowedPropTable);

	UPROPERTY(EditDefaultsOnly, Category="RiftBubble")
	TObjectPtr<UDataTable> DefaultAllowedPropTable;

	UPROPERTY(Transient)
	TObjectPtr<UDataTable> AllowedPropTable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="RiftBubble")
	TArray<TSoftClassPtr<ABuildingActor>> AllowedPropClasses;

};

