// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortWrapSkeletalMeshActor.generated.h"

class ACustomItemWrapModifier;
class UAthenaItemWrapDefinition;
enum class EItemWrapMaterialType : uint8;

UCLASS()
class AFortWrapSkeletalMeshActor : public ASkeletalMeshActor
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWrapApplied);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	ACustomItemWrapModifier* GetWrapModifier() const;

	UFUNCTION(BlueprintCallable)
	void SetWrap(UAthenaItemWrapDefinition* NewWrap, EItemWrapMaterialType MaterialType);

private:
	UPROPERTY(EditAnywhere, Category="Materials")
	TObjectPtr<UAthenaItemWrapDefinition> WrapToApply;

	UPROPERTY(EditAnywhere, Category="Materials")
	EItemWrapMaterialType WrapMaterialType;

	UPROPERTY(EditAnywhere, Category="Materials")
	TArray<FMcpVariantChannelInfo> VariantData;

	UPROPERTY(EditAnywhere, Category="Materials")
	TObjectPtr<ACustomItemWrapModifier> ItemWrapModifier;

	UPROPERTY()
	bool bHasSectionLimit;

	UPROPERTY(EditAnywhere, Category="Config", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EItemWrapSectionNames", EditCondition="bHasSectionLimit"))
	int32 MaterialSectionMask;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnWrapApplied OnWrapApplied;

};

